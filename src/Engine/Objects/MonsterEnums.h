#pragma once

#include <cstdint>

#include "Utility/Segment.h"

// TODO(captainurist): Rename to MonsterId?
/**
 * Enum of all monsters in the game.
 *
 * DON'T EDIT, THIS IS AUTOGENERATED CODE.
 *
 * @see runMonsterIdCodeGen
 */
enum class MONSTER_TYPE {
    MONSTER_INVALID = 0,
    MONSTER_ANGEL_A = 1,                     // "Angel".
    MONSTER_ANGEL_B = 2,                     // "Angel Lord".
    MONSTER_ANGEL_C = 3,                     // "Archangel".
    MONSTER_ARCHER_A = 4,                    // "Archer".
    MONSTER_ARCHER_B = 5,                    // "Bowman".
    MONSTER_ARCHER_C = 6,                    // "Elite Archer".
    MONSTER_BAT_A = 7,                       // "Giant Bat".
    MONSTER_BAT_B = 8,                       // "Vampire Bat".
    MONSTER_BAT_C = 9,                       // "Inferno Bat".
    MONSTER_BEHEMOTH_A = 10,                 // "Young Behemoth".
    MONSTER_BEHEMOTH_B = 11,                 // "Behemoth".
    MONSTER_BEHEMOTH_C = 12,                 // "Ancient Behemoth".
    MONSTER_BEHOLDER_A = 13,                 // "Floating Eye".
    MONSTER_BEHOLDER_B = 14,                 // "Gazer".
    MONSTER_BEHOLDER_C = 15,                 // "Evil Eye".
    MONSTER_CLERIC_MOON_A = 16,              // "Acolyte of the Moon".
    MONSTER_CLERIC_MOON_B = 17,              // "Cleric of the Moon".
    MONSTER_CLERIC_MOON_C = 18,              // "Priest of the Moon".
    MONSTER_CLERIC_SUN_A = 19,               // "Acolyte of the Sun".
    MONSTER_CLERIC_SUN_B = 20,               // "Cleric of the Sun".
    MONSTER_CLERIC_SUN_C = 21,               // "Priest of the Sun".
    MONSTER_DEVIL_A = 22,                    // "Devil Worker".
    MONSTER_DEVIL_B = 23,                    // "Devil Warrior".
    MONSTER_DEVIL_C = 24,                    // "Devil Captain".
    MONSTER_DRAGON_A = 25,                   // "Green Dragon".
    MONSTER_DRAGON_B = 26,                   // "Blue Dragon".
    MONSTER_DRAGON_C = 27,                   // "Red Dragon".
    MONSTER_DRAGONFLY_A = 28,                // "Dragonfly".
    MONSTER_DRAGONFLY_B = 29,                // "Fire Dragonfly".
    MONSTER_DRAGONFLY_C = 30,                // "Queen Dragonfly".
    MONSTER_DWARF_A = 31,                    // "Dwarven Soldier".
    MONSTER_DWARF_B = 32,                    // "Dwarven Lieutenant".
    MONSTER_DWARF_C = 33,                    // "Dwarven Commander".
    MONSTER_ELEMENTAL_AIR_A = 34,            // "Tempest".
    MONSTER_ELEMENTAL_AIR_B = 35,            // "Cyclone".
    MONSTER_ELEMENTAL_AIR_C = 36,            // "Air Elemental".
    MONSTER_ELEMENTAL_EARTH_A = 37,          // "Clay Elemental".
    MONSTER_ELEMENTAL_EARTH_B = 38,          // "Stone Elemental".
    MONSTER_ELEMENTAL_EARTH_C = 39,          // "Earth Elemental".
    MONSTER_ELEMENTAL_FIRE_A = 40,           // "Warden of Fire".
    MONSTER_ELEMENTAL_FIRE_B = 41,           // "Guardian of Flame".
    MONSTER_ELEMENTAL_FIRE_C = 42,           // "Fire Elemental".
    MONSTER_ELEMENTAL_LIGHT_A = 43,          // "Lesser Light Elemental".
    MONSTER_ELEMENTAL_LIGHT_B = 44,          // "Light Elemental".
    MONSTER_ELEMENTAL_LIGHT_C = 45,          // "Greater Light Elemental".
    MONSTER_ELEMENTAL_WATER_A = 46,          // "Sprite".
    MONSTER_ELEMENTAL_WATER_B = 47,          // "Sylph".
    MONSTER_ELEMENTAL_WATER_C = 48,          // "Water Elemental".
    MONSTER_ELF_ARCHER_A = 49,               // "Elven Archer".
    MONSTER_ELF_ARCHER_B = 50,               // "Elven Scout".
    MONSTER_ELF_ARCHER_C = 51,               // "Elven Ranger".
    MONSTER_ELF_SPEARMAN_A = 52,             // "Elven Warrior".
    MONSTER_ELF_SPEARMAN_B = 53,             // "Elven Defender".
    MONSTER_ELF_SPEARMAN_C = 54,             // "Elven Lancer".
    MONSTER_FIGHTER_CHAIN_A = 55,            // "Conscript".
    MONSTER_FIGHTER_CHAIN_B = 56,            // "Soldier".
    MONSTER_FIGHTER_CHAIN_C = 57,            // "Fighter".
    MONSTER_FIGHTER_LEATHER_A = 58,          // "Robber".
    MONSTER_FIGHTER_LEATHER_B = 59,          // "Raider".
    MONSTER_FIGHTER_LEATHER_C = 60,          // "Bandit".
    MONSTER_FIGHTER_PLATE_A = 61,            // "Initiate of the Sword".
    MONSTER_FIGHTER_PLATE_B = 62,            // "Champion of the Sword".
    MONSTER_FIGHTER_PLATE_C = 63,            // "Master of the Sword".
    MONSTER_GARGOYLE_A = 64,                 // "Stone Gargoyle".
    MONSTER_GARGOYLE_B = 65,                 // "Marble Gargoyle".
    MONSTER_GARGOYLE_C = 66,                 // "Obsidian Gargoyle".
    MONSTER_GENIE_A = 67,                    // "Djinni".
    MONSTER_GENIE_B = 68,                    // "Genie".
    MONSTER_GENIE_C = 69,                    // "Efreet".
    MONSTER_GHOST_A = 70,                    // "Shade".
    MONSTER_GHOST_B = 71,                    // "Specter".
    MONSTER_GHOST_C = 72,                    // "Ghost".
    MONSTER_GOBLIN_A = 73,                   // "Goblin".
    MONSTER_GOBLIN_B = 74,                   // "Hobgoblin".
    MONSTER_GOBLIN_C = 75,                   // "Goblin Lord".
    MONSTER_GOG_A = 76,                      // "Gogling".
    MONSTER_GOG_B = 77,                      // "Gog".
    MONSTER_GOG_C = 78,                      // "Magog".
    MONSTER_GOLEM_A = 79,                    // "Bronze Golem".
    MONSTER_GOLEM_B = 80,                    // "Brass Golem".
    MONSTER_GOLEM_C = 81,                    // "Gold Golem".
    MONSTER_GRIFFIN_A = 82,                  // "Griffin".
    MONSTER_GRIFFIN_B = 83,                  // "Hunting Griffin".
    MONSTER_GRIFFIN_C = 84,                  // "Royal Griffin".
    MONSTER_HARPY_A = 85,                    // "Harpy".
    MONSTER_HARPY_B = 86,                    // "Harpy Hag".
    MONSTER_HARPY_C = 87,                    // "Harpy Queen".
    MONSTER_HYDRA_A = 88,                    // "Fire Hydra".
    MONSTER_HYDRA_B = 89,                    // "Air Hydra".
    MONSTER_HYDRA_C = 90,                    // "Chaos Hydra".
    MONSTER_LICH_A = 91,                     // "Lich".
    MONSTER_LICH_B = 92,                     // "Power Lich".
    MONSTER_LICH_C = 93,                     // "Lich King".
    MONSTER_MAGE_A = 94,                     // "Sorcerer".
    MONSTER_MAGE_B = 95,                     // "Wizard".
    MONSTER_MAGE_C = 96,                     // "Archmage".
    MONSTER_MANTICORE_A = 97,                // "Minicore".
    MONSTER_MANTICORE_B = 98,                // "Manticore".
    MONSTER_MANTICORE_C = 99,                // "Scorpicore".
    MONSTER_MEDUSA_A = 100,                  // "Medusa".
    MONSTER_MEDUSA_B = 101,                  // "Queen Medusa".
    MONSTER_MEDUSA_C = 102,                  // "Empress Medusa".
    MONSTER_MINOTAUR_A = 103,                // "Minotaur".
    MONSTER_MINOTAUR_B = 104,                // "Minotaur Headsman".
    MONSTER_MINOTAUR_C = 105,                // "Minotaur Lord".
    MONSTER_MONK_A = 106,                    // "Monk".
    MONSTER_MONK_B = 107,                    // "Initiate".
    MONSTER_MONK_C = 108,                    // "Master".
    MONSTER_NECROMANCER_A = 109,             // "Necromancer".
    MONSTER_NECROMANCER_B = 110,             // "Speaker for the Dead".
    MONSTER_NECROMANCER_C = 111,             // "Queen of the Dead".
    MONSTER_OOZE_A = 112,                    // "Emerald Ooze".
    MONSTER_OOZE_B = 113,                    // "Sapphire Ooze".
    MONSTER_OOZE_C = 114,                    // "Bloodstone Ooze".
    MONSTER_PEASANT_DWARF_FEMALE_A_A = 115,  // "Peasant".
    MONSTER_PEASANT_DWARF_FEMALE_A_B = 116,  // "Peasant".
    MONSTER_PEASANT_DWARF_FEMALE_A_C = 117,  // "Peasant".
    MONSTER_PEASANT_DWARF_FEMALE_B_A = 118,  // "Peasant".
    MONSTER_PEASANT_DWARF_FEMALE_B_B = 119,  // "Peasant".
    MONSTER_PEASANT_DWARF_FEMALE_B_C = 120,  // "Peasant".
    MONSTER_PEASANT_DWARF_FEMALE_C_A = 121,  // "Peasant".
    MONSTER_PEASANT_DWARF_FEMALE_C_B = 122,  // "Peasant".
    MONSTER_PEASANT_DWARF_FEMALE_C_C = 123,  // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_A_A = 124,    // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_A_B = 125,    // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_A_C = 126,    // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_B_A = 127,    // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_B_B = 128,    // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_B_C = 129,    // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_C_A = 130,    // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_C_B = 131,    // "Peasant".
    MONSTER_PEASANT_DWARF_MALE_C_C = 132,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_A_A = 133,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_A_B = 134,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_A_C = 135,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_B_A = 136,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_B_B = 137,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_B_C = 138,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_C_A = 139,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_C_B = 140,    // "Peasant".
    MONSTER_PEASANT_ELF_FEMALE_C_C = 141,    // "Peasant".
    MONSTER_PEASANT_ELF_MALE_A_A = 142,      // "Peasant".
    MONSTER_PEASANT_ELF_MALE_A_B = 143,      // "Peasant".
    MONSTER_PEASANT_ELF_MALE_A_C = 144,      // "Peasant".
    MONSTER_PEASANT_ELF_MALE_B_A = 145,      // "Peasant".
    MONSTER_PEASANT_ELF_MALE_B_B = 146,      // "Peasant".
    MONSTER_PEASANT_ELF_MALE_B_C = 147,      // "Peasant".
    MONSTER_PEASANT_ELF_MALE_C_A = 148,      // "Peasant".
    MONSTER_PEASANT_ELF_MALE_C_B = 149,      // "Peasant".
    MONSTER_PEASANT_ELF_MALE_C_C = 150,      // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_A_A = 151, // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_A_B = 152, // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_A_C = 153, // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_B_A = 154, // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_B_B = 155, // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_B_C = 156, // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_C_A = 157, // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_C_B = 158, // "Peasant".
    MONSTER_PEASANT_HUMAN1_FEMALE_C_C = 159, // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_A_A = 160,   // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_A_B = 161,   // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_A_C = 162,   // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_B_A = 163,   // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_B_B = 164,   // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_B_C = 165,   // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_C_A = 166,   // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_C_B = 167,   // "Peasant".
    MONSTER_PEASANT_HUMAN1_MALE_C_C = 168,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_A_A = 169,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_A_B = 170,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_A_C = 171,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_B_A = 172,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_B_B = 173,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_B_C = 174,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_C_A = 175,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_C_B = 176,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_MALE_C_C = 177,   // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_A_A = 178, // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_A_B = 179, // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_A_C = 180, // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_B_A = 181, // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_B_B = 182, // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_B_C = 183, // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_C_A = 184, // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_C_B = 185, // "Peasant".
    MONSTER_PEASANT_HUMAN2_FEMALE_C_C = 186, // "Peasant".
    MONSTER_RAT_A = 187,                     // "Giant Rat".
    MONSTER_RAT_B = 188,                     // "Lightning Rat".
    MONSTER_RAT_C = 189,                     // "Fire Rat".
    MONSTER_ROBOT_A = 190,                   // "Seeker Droid".
    MONSTER_ROBOT_B = 191,                   // "Sentinel Droid".
    MONSTER_ROBOT_C = 192,                   // "Assassin Droid".
    MONSTER_ROC_A = 193,                     // "Roc".
    MONSTER_ROC_B = 194,                     // "Greater Roc".
    MONSTER_ROC_C = 195,                     // "Thunderbird".
    MONSTER_SEA_MONSTER_A = 196,             // "Giant Shark".
    MONSTER_SEA_MONSTER_B = 197,             // "Piranha Shark".
    MONSTER_SEA_MONSTER_C = 198,             // "Dragon Shark".
    MONSTER_SKELETON_WARRIOR_A = 199,        // "Skeleton".
    MONSTER_SKELETON_WARRIOR_B = 200,        // "Skeleton Warrior".
    MONSTER_SKELETON_WARRIOR_C = 201,        // "Skeleton Lord".
    MONSTER_SPIDER_A = 202,                  // "Giant Spider".
    MONSTER_SPIDER_B = 203,                  // "Venemous Spider".
    MONSTER_SPIDER_C = 204,                  // "Widowmaker".
    MONSTER_SWORDSMAN_A = 205,               // "Swordsman".
    MONSTER_SWORDSMAN_B = 206,               // "Guard".
    MONSTER_SWORDSMAN_C = 207,               // "Adventurer".
    MONSTER_THIEF_A = 208,                   // "Thief".
    MONSTER_THIEF_B = 209,                   // "Rogue".
    MONSTER_THIEF_C = 210,                   // "Master Thief".
    MONSTER_TITAN_A = 211,                   // "Titan".
    MONSTER_TITAN_B = 212,                   // "Storm Titan".
    MONSTER_TITAN_C = 213,                   // "Blood Titan".
    MONSTER_TROGLODYTE_A = 214,              // "Troglodyte Drone".
    MONSTER_TROGLODYTE_B = 215,              // "Troglodyte Soldier".
    MONSTER_TROGLODYTE_C = 216,              // "Troglodyte Queen".
    MONSTER_VAMPIRE_A = 217,                 // "Minion Vampire".
    MONSTER_VAMPIRE_B = 218,                 // "Vampire".
    MONSTER_VAMPIRE_C = 219,                 // "Elder Vampire".
    MONSTER_WARLOCK_A = 220,                 // "Fire Warlock".
    MONSTER_WARLOCK_B = 221,                 // "Water Warlock".
    MONSTER_WARLOCK_C = 222,                 // "Air Warlock".
    MONSTER_WIGHT_A = 223,                   // "Wight".
    MONSTER_WIGHT_B = 224,                   // "Wraith".
    MONSTER_WIGHT_C = 225,                   // "Barrow Wight".
    MONSTER_WYVERN_A = 226,                  // "Wyvern".
    MONSTER_WYVERN_B = 227,                  // "Horned Wyvern".
    MONSTER_WYVERN_C = 228,                  // "Ancient Wyvern".
    MONSTER_ZOMBIE_A = 229,                  // "Rotted Corpse".
    MONSTER_ZOMBIE_B = 230,                  // "Walking Dead".
    MONSTER_ZOMBIE_C = 231,                  // "Zombie".
    MONSTER_PEASANT_GOBLIN_FEMALE_A_A = 232, // "Peasant".
    MONSTER_PEASANT_GOBLIN_FEMALE_A_B = 233, // "Peasant".
    MONSTER_PEASANT_GOBLIN_FEMALE_A_C = 234, // "Peasant".
    MONSTER_PEASANT_GOBLIN_FEMALE_B_A = 235, // "Peasant".
    MONSTER_PEASANT_GOBLIN_FEMALE_B_B = 236, // "Peasant".
    MONSTER_PEASANT_GOBLIN_FEMALE_B_C = 237, // "Peasant".
    MONSTER_PEASANT_GOBLIN_FEMALE_C_A = 238, // "Peasant".
    MONSTER_PEASANT_GOBLIN_FEMALE_C_B = 239, // "Peasant".
    MONSTER_PEASANT_GOBLIN_FEMALE_C_C = 240, // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_A_A = 241,   // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_A_B = 242,   // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_A_C = 243,   // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_B_A = 244,   // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_B_B = 245,   // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_B_C = 246,   // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_C_A = 247,   // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_C_B = 248,   // "Peasant".
    MONSTER_PEASANT_GOBLIN_MALE_C_C = 249,   // "Peasant".
    MONSTER_TROLL_A = 250,                   // "Swamp Troll".
    MONSTER_TROLL_B = 251,                   // "River Troll".
    MONSTER_TROLL_C = 252,                   // "Mountain Troll".
    MONSTER_TREANT_A = 253,                  // "Tree".
    MONSTER_TREANT_B = 254,                  // "Tree".
    MONSTER_TREANT_C = 255,                  // "Tree".
    MONSTER_GHOUL_A = 256,                   // "Ghast".
    MONSTER_GHOUL_B = 257,                   // "Ghoul".
    MONSTER_GHOUL_C = 258,                   // "Revenant".
    MONSTER_BLASTERGUY_A = 259,              // "Tolberti".
    MONSTER_BLASTERGUY_B = 260,              // "Robert the Wise".
    MONSTER_BLASTERGUY_C = 261,              // "Blaster Guy C".
    MONSTER_ULTRA_DRAGON_A = 262,            // "Mega-Dragon".
    MONSTER_ULTRA_DRAGON_B = 263,            // "Mega-Dragon".
    MONSTER_ULTRA_DRAGON_C = 264,            // "Mega-Dragon".
    MONSTER_265 = 265,
    MONSTER_266 = 266,
    MONSTER_267 = 267,
    MONSTER_268 = 268,
    MONSTER_269 = 269,
    MONSTER_270 = 270,
    MONSTER_271 = 271,
    MONSTER_272 = 272,
    MONSTER_273 = 273,
    MONSTER_274 = 274,
    MONSTER_275 = 275,
    MONSTER_276 = 276,
    MONSTER_277 = 277,

    MONSTER_FIRST = MONSTER_ANGEL_A,
    MONSTER_LAST = MONSTER_277,

    MONSTER_FIRST_ARENA = MONSTER_ANGEL_A,
    MONSTER_LAST_ARENA = MONSTER_GHOUL_C
};
using enum MONSTER_TYPE;

inline Segment<MONSTER_TYPE> allArenaMonsters() {
    return {MONSTER_FIRST_ARENA, MONSTER_LAST_ARENA};
}

/*  335 */
enum class MONSTER_SPECIAL_ABILITY_TYPE {
    MONSTER_SPECIAL_ABILITY_NONE = 0x0,
    MONSTER_SPECIAL_ABILITY_SHOT = 0x1,
    MONSTER_SPECIAL_ABILITY_SUMMON = 0x2,
    MONSTER_SPECIAL_ABILITY_EXPLODE = 0x3,
};
using enum MONSTER_SPECIAL_ABILITY_TYPE;

enum class MONSTER_MOVEMENT_TYPE {
    MONSTER_MOVEMENT_TYPE_SHORT = 0x0,
    MONSTER_MOVEMENT_TYPE_MEDIUM = 0x1,
    MONSTER_MOVEMENT_TYPE_LONG = 0x2,
    MONSTER_MOVEMENT_TYPE_GLOBAL = 0x3,
    MONSTER_MOVEMENT_TYPE_FREE = 0x4,
    MONSTER_MOVEMENT_TYPE_STATIONARY = 0x5,
};
using enum MONSTER_MOVEMENT_TYPE;

/*  336 */
enum class MONSTER_SUPERTYPE {
    MONSTER_SUPERTYPE_UNDEAD = 0x1,
    MONSTER_SUPERTYPE_KREEGAN = 0x2,
    MONSTER_SUPERTYPE_DRAGON = 0x3,
    MONSTER_SUPERTYPE_ELF = 0x4,
    MONSTER_SUPERTYPE_WATER_ELEMENTAL = 0x5,
    MONSTER_SUPERTYPE_TREANT = 0x6,
    MONSTER_SUPERTYPE_TITAN = 0x7,
    MONSTER_SUPERTYPE_8 = 0x8,
};
using enum MONSTER_SUPERTYPE;

enum class SPECIAL_ATTACK_TYPE : uint8_t {
    SPECIAL_ATTACK_NONE = 0,
    SPECIAL_ATTACK_CURSE = 1,
    SPECIAL_ATTACK_WEAK = 2,
    SPECIAL_ATTACK_SLEEP = 3,
    SPECIAL_ATTACK_DRUNK = 4,
    SPECIAL_ATTACK_INSANE = 5,
    SPECIAL_ATTACK_POISON_WEAK = 6,
    SPECIAL_ATTACK_POISON_MEDIUM = 7,
    SPECIAL_ATTACK_POISON_SEVERE = 8,
    SPECIAL_ATTACK_DISEASE_WEAK = 9,
    SPECIAL_ATTACK_DISEASE_MEDIUM = 10,
    SPECIAL_ATTACK_DISEASE_SEVERE = 11,
    SPECIAL_ATTACK_PARALYZED = 12,
    SPECIAL_ATTACK_UNCONSCIOUS = 13,
    SPECIAL_ATTACK_DEAD = 14,
    SPECIAL_ATTACK_PETRIFIED = 15,
    SPECIAL_ATTACK_ERADICATED = 16,
    SPECIAL_ATTACK_BREAK_ANY = 17,
    SPECIAL_ATTACK_BREAK_ARMOR = 18,
    SPECIAL_ATTACK_BREAK_WEAPON = 19,
    SPECIAL_ATTACK_STEAL = 20,
    SPECIAL_ATTACK_AGING = 21,
    SPECIAL_ATTACK_MANA_DRAIN = 22,
    SPECIAL_ATTACK_FEAR = 23,
};
using enum SPECIAL_ATTACK_TYPE;

enum class MonsterHostility {
    HOSTILITY_FRIENDLY = 0,
    HOSTILITY_CLOSE = 1,
    HOSTILITY_SHORT = 2,
    HOSTILITY_MEDIUM = 3,
    HOSTILITY_LONG = 4,

    HOSTILITY_FIRST = HOSTILITY_FRIENDLY,
    HOSTILITY_LAST = HOSTILITY_LONG
};
using enum MonsterHostility;
