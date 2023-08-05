#pragma once

#include <cstdint>

#define PARTY_AUTONOTES_BIT__EMERALD_FIRE_FOUNTAIN 2

// reference "quests.txt" and pQuestTable
enum PARTY_QUEST_BITS : uint16_t {
    QBIT_EMERALD_ISLAND_RED_POTION_ACTIVE = 1,
    QBIT_EMERALD_ISLAND_SEASHELL_ACTIVE = 2,
    QBIT_EMERALD_ISLAND_LONGBOW_ACTIVE = 3,
    QBIT_EMERALD_ISLAND_PLATE_ACTIVE = 4,
    QBIT_EMERALD_ISLAND_LUTE_ACTIVE = 5,
    QBIT_EMERALD_ISLAND_HAT_ACTIVE = 6,

    QBIT_EMERALD_ISLAND_MARGARETH_OFF = 17,

    QBIT_EVENMORN_MAP_FOUND = 64,

    QBIT_HARMONDALE_REBUILT = 98,
    QBIT_LIGHT_PATH = 99,
    QBIT_DARK_PATH = 100,

    QBIT_ESCAPED_EMERALD_ISLE = 136,

    QBIT_OBELISK_IN_HARMONDALE_FOUND = 164,
    QBIT_OBELISK_IN_ERATHIA_FOUND = 165,
    QBIT_OBELISK_IN_TULAREAN_FOREST_FOUND = 166,
    QBIT_OBELISK_IN_DEYJA_FOUND = 167,
    QBIT_OBELISK_IN_BRACADA_DESERT_FOUND = 168,
    QBIT_OBELISK_IN_CELESTE_FOUND = 169,
    QBIT_OBELISK_IN_THE_PIT_FOUND = 170,
    QBIT_OBELISK_IN_EVENMORN_ISLAND_FOUND = 171,
    QBIT_OBELISK_IN_MOUNT_NIGHON_FOUND = 172,
    QBIT_OBELISK_IN_BARROW_DOWNS_FOUND = 173,
    QBIT_OBELISK_IN_LAND_OF_THE_GIANTS_FOUND = 174,
    QBIT_OBELISK_IN_TATALIA_FOUND = 175,
    QBIT_OBELISK_IN_AVLEE_FOUND = 176,
    QBIT_OBELISK_IN_STONE_CITY_FOUND = 177,

    QBIT_OBELISK_TREASURE_FOUND = 178,

    QBIT_SPLITTER_FOUND = 184,

    QBIT_FOUNTAIN_IN_HARMONDALE_ACTIVATED = 206,
    QBIT_FOUNTAIN_IN_STEADWICK_ACTIVATED = 207,
    QBIT_FOUNTAIN_IN_PIERPONT_ACTIVATED = 208,
    QBIT_FOUNTAIN_IN_CELESTIA_ACTIVATED = 209,
    QBIT_FOUNTAIN_IN_THE_PIT_ACTIVATED = 210,
    QBIT_FOUNTAIN_IN_MOUNT_NIGHON_ACTIVATED = 211,

    QBIT_ARCOMAGE_CHAMPION = 238,  // won all arcomage games
    QBIT_DIVINE_INTERVENTION_RETRIEVED = 239,
};

/*  355 */
enum PARTY_FLAGS_1 : int32_t {
    PARTY_FLAGS_1_UNUSED = 0x0002, // was force drawing
    PARTY_FLAGS_1_WATER_DAMAGE = 0x0004,
    PARTY_FLAGS_1_AIRBORNE = 0x0008,
    PARTY_FLAGS_1_ALERT_RED = 0x0010,
    PARTY_FLAGS_1_ALERT_YELLOW = 0x0020,
    PARTY_FLAGS_1_ALERT_RED_OR_YELLOW = 0x0030,
    PARTY_FLAGS_1_STANDING_ON_WATER = 0x0080,
    // In vanilla landing flag used to control for no damage landings
    // OE now uses this as a flag for landing from flight
    PARTY_FLAGS_1_LANDING = 0x0100,
    PARTY_FLAGS_1_BURNING = 0x0200,

    // New to OE - flag used to negate landing damage after jumping
    PARTY_FLAGS_1_JUMPING = 0x0400
};
enum PARTY_FLAGS_2 : int32_t {
    PARTY_FLAGS_2_RUNNING = 0x2,
};

/*  347 */
enum PARTY_BUFF_INDEX {
    PARTY_BUFF_RESIST_AIR = 0,
    PARTY_BUFF_RESIST_BODY = 1,
    PARTY_BUFF_DAY_OF_GODS = 2,
    PARTY_BUFF_DETECT_LIFE = 3,
    PARTY_BUFF_RESIST_EARTH = 4,
    PARTY_BUFF_FEATHER_FALL = 5,
    PARTY_BUFF_RESIST_FIRE = 6,
    PARTY_BUFF_FLY = 7,
    PARTY_BUFF_HASTE = 8,
    PARTY_BUFF_HEROISM = 9,
    PARTY_BUFF_IMMOLATION = 10,
    PARTY_BUFF_INVISIBILITY = 11,
    PARTY_BUFF_RESIST_MIND = 12,
    PARTY_BUFF_PROTECTION_FROM_MAGIC = 13,
    PARTY_BUFF_SHIELD = 14,
    PARTY_BUFF_STONE_SKIN = 15,
    PARTY_BUFF_TORCHLIGHT = 16,
    PARTY_BUFF_RESIST_WATER = 17,
    PARTY_BUFF_WATER_WALK = 18,
    PARTY_BUFF_WIZARD_EYE = 19,
};

/*  300 */
enum PartyAction : uint32_t {
    PARTY_INVALID = 0,
    PARTY_TurnLeft = 1,
    PARTY_TurnRight = 2,
    PARTY_StrafeLeft = 3,
    PARTY_StrafeRight = 4,
    PARTY_WalkForward = 5,
    PARTY_WalkBackward = 6,
    PARTY_LookUp = 7,
    PARTY_LookDown = 8,
    PARTY_CenterView = 9,
    PARTY_unkA = 10,
    PARTY_unkB = 11,
    PARTY_Jump = 12,
    PARTY_FlyUp = 13,
    PARTY_FlyDown = 14,
    PARTY_Land = 15,
    PARTY_RunForward = 16,
    PARTY_RunBackward = 17,
    PARTY_FastTurnLeft = 18,
    PARTY_FastTurnRight = 19,

    PARTY_dword = 0xFFFFFFFF
};

enum class PartyAlignment: int32_t {
    PartyAlignment_Good = 0,
    PartyAlignment_Neutral = 1,
    PartyAlignment_Evil = 2
};
using enum PartyAlignment;

/**
 * Controls gold receiving mechanics.
 */
enum class GoldReceivePolicy {
    GOLD_RECEIVE_SHARE,          // default behaviour: receive gold and share it with hirelings
    GOLD_RECEIVE_NOSHARE_MSG,    // receive gold without sharing, displays status message
    GOLD_RECEIVE_NOSHARE_SILENT  // receive gold without sharing and status message
};
using enum GoldReceivePolicy;
