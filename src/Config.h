// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <raylib-cpp.hpp>
#include "utils/Bootstrap.h"

class Config {
public:
// GENERAL CONFIGS
    static const char* GAME_TITLE;
    static const char * WINDOW_TITLE;
    static const int WINDOW_WIDTH;
    static const int WINDOW_HEIGHT;

// UI CONFIGS
    static const float DEFAULT_FONT_SIZE;
    static const float DEFAULT_PADDING;
    static const float DEFAULT_LINE_SPACING;
    static const float DEFAULT_TEXT_SPACING;
    static const float TITLE_VALUE_LIST_TEXT_SIZE;
    static const float TITLE_VALUE_LIST_TEXT_SPACING;
    static const Color DEFAULT_UI_TEXT_COLOR;
    static const Color DEFAULT_FONT_COLOR;

// STYLE CONFIGS
    static const Color TERRAIN_DEFAULT_COLOR;
    static const Color PLAYER_COLOR;
    static const Color HUMAN_COLOR;
    static const Color ZOMBIE_COLOR;
    static const Color SMELL_RADIUS_COLOR;
    static const Color ATTACK_RADIUS_COLOR;
    static const Color SOUND_RADIUS_COLOR;
    static const Color PATH_COLOR;
    static const Color TARGET_COLOR;

// LOOT CONFIGS
    static const float DEFAULT_LOOT_AMOUNT;
    static const float DEFAULT_LOOT_SPAWN_POSITION_X;
    static const float DEFAULT_LOOT_SPAWN_POSITION_Y;
    static const float FOOD_DEFAULT_SIZE;
    
// PLAYER CONFIGS
    static const float PLAYER_HEALTH;
    static const float PLAYER_STRENGTH;
    static const float PLAYER_AGILITY;
    static const float PLAYER_HEARING_RADIUS;
    static const float PLAYER_ATTACK_RADIUS;
    static const float PLAYER_SPAWN_POSITION_X;
    static const float PLAYER_SPAWN_POSITION_Y;
    static const float PLAYER_WALK_COEF;
    static const float PLAYER_RUN_COEF;

// HUMAN CONFIGS
    static const float HUMAN_DEFAULT_HEALTH;
    static const float HUMAN_DEFAULT_STRENGTH;
    static const float HUMAN_DEFAULT_AGILITY;
    static const float HUMAN_DEFAULT_STAMINA;
    static const float HUMAN_WALK_COEF;
    static const float HUMAN_RUN_COEF;
    static const float HUMAN_HEARING_RADIUS;
    static const float HUMAN_ATTACK_RADIUS;
    static const float HUMAN_SPAWN_POSITION_X;
    static const float HUMAN_SPAWN_POSITION_Y;
    static const float HUMAN_DEFAULT_TARGET_X;
    static const float HUMAN_DEFAULT_TARGET_Y;
    static const float HUMAN_MOVE_TRESHOLD;

// ZOMBI CONFIGS
    static const size_t ZOMBIES_COUNT;
    static const float ZOMBIE_WALK_COEF;
    static const float ZOMBIE_RUN_COEF;
    static const float ZOMBIE_HEALTH;
    static const float ZOMBIE_STRENGTH;
    static const float ZOMBIE_AGILITY;
    static const float ZOMBIE_HEARING_RADIUS;
    static const float ZOMBIE_ATTACK_RADIUS;
    static const float ZOMBIE_SPAWN_POSITION_X;
    static const float ZOMBIE_SPAWN_POSITION_Y;
    static const float ZOMBIE_DEFAULT_TARGET_POSITION_X;
    static const float ZOMBIE_DEFAULT_TARGET_POSITION_Y;
    
// SOUND CONFIGS
    static const float SOUND_MIN_RADIUS;
    static const float SOUND_MAX_RADIUS;
    static const float SOUND_RADIUS_STEP;

};

#endif // CONFIG_H
