#include "CodeGenOptions.h"

#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>

#include "Application/GameStarter.h"
#include "Engine/Tables/ItemTable.h"
#include "Engine/Tables/BuildingTable.h"
#include "Engine/Events/EventMap.h"
#include "Engine/Objects/Monsters.h"
#include "Engine/Snapshots/TableSerialization.h"
#include "Engine/GameResourceManager.h"
#include "Engine/MapInfo.h"

#include "GUI/UI/Houses/TownHall.h"

#include "Library/Lod/LodReader.h"
#include "Library/Random/Random.h"
#include "Library/Serialization/EnumSerialization.h"

#include "Utility/Format.h"
#include "Utility/DataPath.h"
#include "Utility/Exception.h"
#include "Utility/String.h"
#include "Utility/UnicodeCrt.h"

#include "CodeGenEnums.h"
#include "CodeGenMap.h"

// TODO(captainurist): use std::string::contains once Android have full C++23 support.
static auto contains = [](const std::string &haystack, const std::string &needle) {
    return haystack.find(needle) != std::string::npos;
};

int runItemIdCodeGen(CodeGenOptions options, GameResourceManager *resourceManager) {
    ItemTable itemTable;
    itemTable.Initialize(resourceManager);

    CodeGenMap map;
    map.insert(ITEM_NULL, "NULL", "");

    for(ItemId i : itemTable.pItems.indices()) {
        const ItemDesc &desc = itemTable.pItems[i];
        std::string icon = desc.iconName;
        std::string name = desc.name;
        std::string description = desc.pDescription;

        if (icon.empty() || icon == "null") {
            map.insert(i, "", "Unused.");
            continue;
        }

        std::string enumName = toUpperCaseEnum(name);

        if (enumName == "EMPTY_MESSAGE_SCROLL" || enumName == "NAME_OF_MESSAGE") {
            map.insert(i, "", "Empty scroll placeholder, unused.");
            continue;
        }

        if (enumName == "NEWNAME_KEY") {
            map.insert(i, "", "Key placeholder, unused.");
            continue;
        }

        if (contains(enumName, "PLACEHOLDER") || contains(enumName, "SEALED_LETTER")) {
            map.insert(i, "", name + ", unused.");
            continue;
        }

        if (contains(enumName, "ORDERS_FROM_SNERGLE")) {
            map.insert(i, "", name + ", unused remnant from MM6.");
            continue;
        }

        if (enumName == "LICH_JAR") {
            if (contains(description, "Empty")) {
                enumName += "_EMPTY";
            } else {
                enumName += "_FULL";
            }
        }

        if (enumName == "THE_PERFECT_BOW")
            if (!contains(description, "off-balance"))
                enumName += "_FIXED";

        // Shorten enum names for letters.
        if (enumName.starts_with("LETTER_FROM") && contains(enumName, "_TO_"))
            enumName = enumName.substr(0, enumName.find("_TO_"));

        if (desc.uEquipType == ITEM_TYPE_REAGENT) {
            enumName = "REAGENT_" + enumName;
        } else if (desc.uEquipType == ITEM_TYPE_POTION) {
            if (!enumName.starts_with("POTION_"))
                enumName = "POTION_" + enumName;
            if (enumName.ends_with("_POTION"))
                enumName = enumName.substr(0, enumName.size() - 7);
        } else if (desc.uEquipType == ITEM_TYPE_SPELL_SCROLL) {
            enumName = "SCROLL_" + enumName;
        } else if (desc.uEquipType == ITEM_TYPE_BOOK) {
            enumName = "SPELLBOOK_" + enumName;
        } else if (desc.uEquipType == ITEM_TYPE_MESSAGE_SCROLL) {
            if (enumName.ends_with("_RECIPE")) {
                enumName = "RECIPE_" + enumName.substr(0, enumName.size() - 7);
            } else if (!enumName.starts_with("MESSAGE_")) {
                enumName = "MESSAGE_" + enumName;
            }
        } else if (desc.uEquipType == ITEM_TYPE_GOLD) {
            if (description == "A small pile of gold coins.") {
                enumName = "GOLD_SMALL";
            } else if (description == "A pile of gold coins.") {
                enumName = "GOLD_MEDIUM";
            } else if (description == "A large pile of gold coins.") {
                enumName = "GOLD_LARGE";
            } else {
                throw Exception("Unrecognized gold pile description '{}'", description);
            }
        } else if (desc.uEquipType == ITEM_TYPE_GEM) {
            enumName = "GEM_" + enumName;
        }

        if (desc.uMaterial == RARITY_ARTIFACT) {
            enumName = "ARTIFACT_" + enumName;
        } else if (desc.uMaterial == RARITY_RELIC) {
            enumName = "RELIC_" + enumName;
        } else if (desc.uMaterial == RARITY_SPECIAL) {
            enumName = "SPECIAL_" + enumName;
        } else if (description.starts_with("Quest")) {
            enumName = "QUEST_" + enumName;
        }

        map.insert(i, enumName, "");
    }

    map.dump(stdout, "ITEM_");

    return 0;
}

std::string mapIdEnumName(const MapInfo &mapInfo) {
    std::string result = toUpperCaseEnum(mapInfo.pName);
    if (result.starts_with("THE_"))
        result = result.substr(4);
    return result;
}

int runMapIdCodeGen(CodeGenOptions options, GameResourceManager *resourceManager) {
    MapStats mapStats;
    mapStats.Initialize(resourceManager->getEventsFile("MapStats.txt"));

    CodeGenMap map;
    map.insert(MAP_INVALID, "INVALID", "");

    for (MapId i : mapStats.pInfos.indices())
        map.insert(i, mapIdEnumName(mapStats.pInfos[i]), "");

    map.dump(stdout, "MAP_");
    return 0;
}

const MapInfo &mapInfoByFileName(const MapStats &mapStats, const std::string &fileName) {
    auto pos = std::find_if(mapStats.pInfos.begin(), mapStats.pInfos.end(), [&] (const MapInfo &mapInfo) {
        return toLower(mapInfo.pFilename) == toLower(fileName);
    });
    if (pos == mapStats.pInfos.end())
        throw Exception("Unrecognized map '{}'", fileName);
    return *pos;
}

int runBeaconsCodeGen(CodeGenOptions options, GameResourceManager *resourceManager) {
    MapStats mapStats;
    mapStats.Initialize(resourceManager->getEventsFile("MapStats.txt"));

    LodReader gamesLod(makeDataPath("data", "games.lod"));
    std::vector<std::string> fileNames = gamesLod.ls();

    for (size_t i = 0; i < fileNames.size(); i++) {
        const std::string &fileName = fileNames[i];
        if (!fileName.ends_with(".odm") && !fileName.ends_with(".blv"))
            continue; // Not a level file.

        fmt::print("    {{MAP_{}, {}}},\n", mapIdEnumName(mapInfoByFileName(mapStats, fileName)), i);
    }

    return 0;
}

int runHouseIdCodeGen(CodeGenOptions options, GameResourceManager *resourceManager) {
    MapStats mapStats;
    mapStats.Initialize(resourceManager->getEventsFile("MapStats.txt"));

    initializeBuildings(resourceManager->getEventsFile("2dEvents.txt"));
    // ^ Initializes buildingTable.

    std::unordered_map<HouseId, std::set<std::string>> mapNamesByHouseId; // Only arbiter exists on two maps.

    LodReader gamesLod(makeDataPath("data", "games.lod"));
    for (const std::string &fileName : gamesLod.ls()) {
        if (!fileName.ends_with(".odm") && !fileName.ends_with(".blv"))
            continue; // Not a level file.

        std::string mapName = mapIdEnumName(mapInfoByFileName(mapStats, fileName));
        EventMap eventMap = EventMap::load(resourceManager->getEventsFile(fileName.substr(0, fileName.size() - 4) + ".evt"));

        for (const EventTrigger &trigger : eventMap.enumerateTriggers(EVENT_SpeakInHouse)) {
            HouseId houseId = eventMap.event(trigger.eventId, trigger.eventStep).data.house_id;
            if (houseId == HOUSE_INVALID)
                throw Exception("Invalid house id encountered in house event");
            mapNamesByHouseId[houseId].insert(mapName);
        }

        for (const EventTrigger &trigger : eventMap.enumerateTriggers(EVENT_MoveToMap)) {
            HouseId houseId = eventMap.event(trigger.eventId, trigger.eventStep).data.move_map_descr.house_id;
            if (houseId != HOUSE_INVALID)
                mapNamesByHouseId[houseId].insert(mapName);
        }
    }

    CodeGenMap map;
    map.insert(HOUSE_INVALID, "INVALID", "");

    for (HouseId i : buildingTable.indices()) {
        const BuildingDesc &desc = buildingTable[i];
        bool hasMap = mapNamesByHouseId.contains(i);
        std::string mapName;
        if (hasMap)
            mapName = fmt::format("{}", fmt::join(mapNamesByHouseId[i], "_"));

        if (i == HOUSE_JAIL) {
            map.insert(i, "JAIL", "");
        } else if (desc.uType == BUILDING_INVALID && hasMap) {
            map.insert(i, "", fmt::format("Used in MAP_{} but invalid, hmm...", mapName));
        } else if (desc.uType == BUILDING_INVALID) {
            map.insert(i, "", "Unused.");
        } else if (!hasMap && !desc.pName.empty()) {
            map.insert(i, "", fmt::format("Unused {} named \"{}\".", toString(desc.uType), desc.pName));
        } else if (!hasMap) {
            map.insert(i, "", "Unused.");
        } else if (toUpperCaseEnum(desc.pName) == fmt::format("HOUSE_{}", std::to_underlying(i))) {
            map.insert(i, "", fmt::format("Used in MAP_{}, named \"{}\", looks totally like a placeholder...", mapName, desc.pName));
        } else if (desc.uType == BUILDING_HOUSE || desc.uType == BUILDING_MERCENARY_GUILD) {
            map.insert(i, fmt::format("{}_{}", mapName, toUpperCaseEnum(desc.pName)), "");
        } else {
            map.insert(i, fmt::format("{}_{}", toString(desc.uType), mapName), fmt::format("\"{}\".", trim(desc.pName)));
        }
    }

    map.dump(stdout, "HOUSE_");
    return 0;
}

MonsterStats loadMonsterStats(GameResourceManager *resourceManager) {
    TriBlob dmonBlobs;
    dmonBlobs.mm7 = resourceManager->getEventsFile("dmonlist.bin");

    pMonsterList = new MonsterList;
    deserialize(dmonBlobs, pMonsterList);

    MonsterStats result;
    result.Initialize(resourceManager->getEventsFile("monsters.txt"));
    return result;
}

std::string cleanupMonsterIdEnumName(std::string enumName) {
    for (const char *prefix : {"ZBLASTERGUY", "ZULTRA_DRAGON", })
        if (enumName.starts_with(prefix))
            enumName = enumName.substr(1);

    for (const char *prefix : {"ZCAT", "ZCHICKEN", "ZDOG", "ZRAT"})
        if (enumName.starts_with(prefix))
            enumName = "UNUSED_" + enumName.substr(1);

    enumName = replaceAll(enumName, "MALEA", "MALE_A");
    enumName = replaceAll(enumName, "MALEB", "MALE_B");
    enumName = replaceAll(enumName, "MALEC", "MALE_C");

    return enumName;
}

int runMonsterIdCodeGen(CodeGenOptions options, GameResourceManager *resourceManager) {
    MonsterStats monsterStats = loadMonsterStats(resourceManager);

    CodeGenMap map;
    map.insert(MONSTER_INVALID, "INVALID", "");

    for (const MonsterId i : allMonsters()) {
        const MonsterDesc &desc = pMonsterList->pMonsters[i];
        const MonsterInfo &info = monsterStats.pInfos[i];
        std::string enumName = cleanupMonsterIdEnumName(toUpperCaseEnum(desc.pMonsterName));

        std::string comment = info.pName;
        if (comment == "peasant")
            comment = "Peasant";
        if (!comment.empty())
            comment = fmt::format("\"{}\".", trim(comment));

        map.insert(i, enumName, comment);
    }

    map.dump(stdout, "MONSTER_");
    return 0;
}

std::string cleanupMonsterTypeEnumName(std::string enumName) {
    enumName = cleanupMonsterIdEnumName(enumName);

    if (enumName.ends_with("_A")) {
        enumName.resize(enumName.size() - 2);
    } else if (!enumName.empty()) {
        throw Exception("Invalid monster id name");
    }

    return enumName;
}

int runMonsterTypeCodeGen(CodeGenOptions options, GameResourceManager *resourceManager) {
    MonsterStats monsterStats = loadMonsterStats(resourceManager);

    CodeGenMap map;
    map.insert(MONSTER_TYPE_INVALID, "INVALID", "");

    int counter = 0;
    for (const MonsterId i : allMonsters()) {
        if (++counter % 3 != 1)
            continue;

        const MonsterDesc &desc = pMonsterList->pMonsters[i];
        std::string enumName = cleanupMonsterTypeEnumName(toUpperCaseEnum(desc.pMonsterName));

        map.insert(monsterTypeForMonsterId(i), enumName, "");
    }

    map.dump(stdout, "MONSTER_TYPE_");
    return 0;
}

int runBountyHuntCodeGen(CodeGenOptions options, GameResourceManager *resourceManager) {
    // Fill bounty hunt map.
    grng = RandomEngine::create(RANDOM_ENGINE_SEQUENTIAL);
    IndexedArray<std::unordered_set<MonsterId>, HOUSE_FIRST_TOWN_HALL, HOUSE_LAST_TOWN_HALL> monstersByTownHall;
    for (const HouseId townHall : allTownhallHouses()) {
        grng->seed(0);
        while(true) {
            MonsterId monsterId = GUIWindow_TownHall::randomMonsterForHunting(townHall);
            if (!monstersByTownHall[townHall].insert(monsterId).second)
                break;
        }
    }

    // Invert the map.
    std::unordered_map<MonsterId, std::unordered_set<HouseId>> townHallsByMonster;
    for (const HouseId townHall : allTownhallHouses())
        for (const MonsterId monsterId : monstersByTownHall[townHall])
            townHallsByMonster[monsterId].insert(townHall);

    // Reduce the map to monster types & check that it's actually reducible.
    std::unordered_map<MonsterType, std::unordered_set<HouseId>> townHallsByMonsterType;
    for (const MonsterId monsterId : allMonsters()) {
        MonsterType monsterType = monsterTypeForMonsterId(monsterId);
        if (townHallsByMonsterType.contains(monsterType) && townHallsByMonsterType[monsterType] != townHallsByMonster[monsterId])
            throw Exception("Invalid bounty hunt record");

        townHallsByMonsterType[monsterType] = townHallsByMonster[monsterId];
    }

    // Prepare output table.
    std::vector<std::array<std::string, 8>> table;
    for (const MonsterType monsterType : allMonsterTypes()) {
        auto &line = table.emplace_back();
        line[0] = fmt::format("{{{}, ", toString(monsterType));
        line[1] = "{";
        for (const HouseId townHall : townHallsByMonsterType[monsterType])
            line[2 + std::to_underlying(townHall) - std::to_underlying(HOUSE_FIRST_TOWN_HALL)] = toString(townHall) + ", ";
        for (size_t i = 6; i >= 2; i--) {
            if (!line[i].empty()) {
                line[i].resize(line[i].size() - 2); // Drop the last ", ".
                break;
            }
        }
        line[7] = "}},";
    }

    // Dump!
    dumpAligned(stdout, "    ", table);
    return 0;
}

int platformMain(int argc, char **argv) {
    try {
        UnicodeCrt _(argc, argv);
        CodeGenOptions options = CodeGenOptions::parse(argc, argv);
        if (options.helpPrinted)
            return 1;

        GameStarter starter(options);

        GameResourceManager resourceManager;
        resourceManager.openGameResources();

        switch (options.subcommand) {
        case CodeGenOptions::SUBCOMMAND_ITEM_ID: return runItemIdCodeGen(std::move(options), &resourceManager);
        case CodeGenOptions::SUBCOMMAND_MAP_ID: return runMapIdCodeGen(std::move(options), &resourceManager);
        case CodeGenOptions::SUBCOMMAND_BEACON_MAPPING: return runBeaconsCodeGen(std::move(options), &resourceManager);
        case CodeGenOptions::SUBCOMMAND_HOUSE_ID: return runHouseIdCodeGen(std::move(options), &resourceManager);
        case CodeGenOptions::SUBCOMMAND_MONSTER_ID: return runMonsterIdCodeGen(std::move(options), &resourceManager);
        case CodeGenOptions::SUBCOMMAND_MONSTER_TYPE: return runMonsterTypeCodeGen(std::move(options), &resourceManager);
        case CodeGenOptions::SUBCOMMAND_BOUNTY_HUNT: return runBountyHuntCodeGen(std::move(options), &resourceManager);
        default:
            assert(false);
            return 1;
        }
    } catch (const std::exception &e) {
        fmt::print(stderr, "{}\n", e.what());
        return 1;
    }
}
