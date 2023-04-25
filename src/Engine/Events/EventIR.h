#pragma once

#include <array>
#include <string>

#include "Engine/Events.h"
#include "GUI/UI/UIHouseEnums.h"
#include "Engine/Objects/PlayerEnums.h"
#include "Engine/Objects/ItemEnums.h"
#include "Engine/Objects/Chest.h"
#include "Engine/Objects/SpriteObjectType.h"
#include "Engine/Graphics/BSPModel.h"
#include "Media/Audio/AudioPlayer.h"

// TODO(Nik-RE-dev): move to EventEnums.h
enum class SEASON {
    SPRING = 0,
    SUMMER = 1,
    AUTUMN = 2,
    WINTER = 3
};
using enum SEASON;

// TODO(Nik-RE-dev): currently exclusive for MM7, need to be independent from players number
// TODO(Nik-RE-dev): move to EventEnums.h
enum class PLAYER_CHOOSE_POLICY {
    CHOOSE_PLAYER1 = 0,
    CHOOSE_PLAYER2 = 1,
    CHOOSE_PLAYER3 = 2,
    CHOOSE_PLAYER4 = 3,

    CHOOSE_ACTIVE = 4,
    CHOOSE_PARTY = 5,
    CHOOSE_RANDOM = 6
};
using enum PLAYER_CHOOSE_POLICY;

class EventIR {
 public:
    std::string toString() const;
    static EventIR parse(void *data, size_t maxSize);
    int execute(bool canShowMessages, PLAYER_CHOOSE_POLICY *who, bool *mapExitTriggered) const;

    EventType type;
    int step;
    int target_step;
    PLAYER_CHOOSE_POLICY who;
    std::string str;
    union {
        HOUSE_ID house_id;
        int chest_id;
        CHARACTER_EXPRESSION_ID expr_id;
        PlayerSpeech speech_id;
        int text_id;
        SEASON season;
        int event_id;
        int movie_unknown_field;
        struct {
            std::array<int, 6> random_goto;
            int random_goto_len;
        } random_goto_descr;
        struct {
            int npc_id;
            int greeting;
        } npc_descr;
        struct {
            int id;
            ITEM_TYPE item;
            bool is_give;
        } npc_item_descr;
        struct {
            VariableType type;
            int value;
        } variable_descr;
        struct {
            SoundID sound_id;
            int x;
            int y;
        } sound_descr;
        struct {
            DAMAGE_TYPE damage_type;
            int damage;
        } damage_descr;
        struct {
            int type;
            int param;
            int num;
        } actor_descr;
        struct {
            int id;
            ActorAttribute attr;
            int is_set;
        } actor_flag_descr;
        struct {
            SPELL_TYPE spell_id;
            PLAYER_SKILL_MASTERY spell_mastery;
            PLAYER_SKILL_LEVEL spell_level;
            int fromx;
            int fromy;
            int fromz;
            int tox;
            int toy;
            int toz;
        } spell_descr;
        struct {
            int type;
            int level;
            int count;
            int x;
            int y;
            int z;
            int group;
            int name_id;
        } monster_descr;
        struct {
            int years;
            int months;
            int weeks;
            int hours;
            int minutes;
            int seconds;
            int alternative_interval;
        } timer_descr;
        struct {
            bool is_nop;
            bool is_enable;
        } snow_descr;
        struct {
            int cog;
            int hide;
        } sprite_texture_descr;
        struct {
            int door_id;
            int door_new_state;
        } door_descr;
        struct {
            int light_id;
            int is_enable;
        } light_descr;
        struct {
            int npc_id;
            int index;
            int event_id;
        } npc_topic_descr;
        struct {
            int x;
            int y;
            int z;
            int yaw;
            int pitch;
            int zspeed;
            int anim_id;
            int exit_pic_id;
        } move_map_descr;
        struct {
            int cog;
            FaceAttribute face_bit;
            int is_on;
        } faces_bit_descr;
        struct {
            SPRITE_OBJECT_TYPE sprite;
            int x;
            int y;
            int z;
            int speed;
            int count;
            bool random_rotate;
        } summon_item_descr;
        struct {
            int npc_id;
            int location_id;
        } npc_move_descr;
        struct {
            int groups_id;
            int group;
        } npc_groups_descr;
        struct {
            ITEM_TREASURE_LEVEL treasure_level;
            int treasure_type;
            ITEM_TYPE item_id;
        } give_item_descr;
        struct {
            int chest_id;
            CHEST_FLAG flag;
            int is_set;
        } chest_flag_descr;
        struct {
            PLAYER_SKILL_TYPE skill_type;
            PLAYER_SKILL_MASTERY skill_mastery;
            PLAYER_SKILL_LEVEL skill_level;
        } check_skill_descr;
    } data;
};
