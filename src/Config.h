// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <raylib-cpp.hpp>
#include "utils/Bootstrap.h"

class Config {
public:
// STYLE CONFIGS
    static const Color PLAYER_COLOR;
    static const Color HUMAN_COLOR;
    static const Color ZOMBIE_COLOR;
    
    static const Color SMELL_RADIUS_COLOR;
    static const Color ATTACK_RADIUS_COLOR;
    static const Color SOUND_RADIUS_COLOR;
    
    static const Color PATH_COLOR;
    static const Color GOAL_COLOR;
    
    static const Color NEEDS_INFO_TEXT_COLOR;

// GAME CONFIGS
    static const char * WINDOW_TITLE;
    static const int WINDOW_WIDTH;
    static const int WINDOW_HEIGHT;
    static const size_t ZOMBIES_COUNT;
    static const float WALK_COEF;
    static const float RUN_COEF;
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

// HUMAN CONFIGS
    static const float HUMAN_HEALTH;
    static const float HUMAN_STRENGTH;
    static const float HUMAN_AGILITY;
    static const float HUMAN_WALK_SPEED;
    static const float HUMAN_RUN_SPEED;
    static const float HUMAN_HEARING_RADIUS;
    static const float HUMAN_ATTACK_RADIUS;
    static const float HUMAN_SPAWN_POSITION_X;
    static const float HUMAN_SPAWN_POSITION_Y;
    static const float HUMAN_DEFAULT_TARGET_X;
    static const float HUMAN_DEFAULT_TARGET_Y;
    static const float HUMAN_MOVE_TRESHOLD;
    static const float HUMAN_AIR_DEFAULT_NEED_VALUE;
    static const float HUMAN_WATER_DEFAULT_NEED_VALUE;
    static const float HUMAN_FOOD_DEFAULT_NEED_VALUE;
    static const float HUMAN_HEAT_DEFAULT_NEED_VALUE;
    static const float HUMAN_CLOTHES_DEFAULT_NEED_VALUE;
    static const float HUMAN_SLEEP_DEFAULT_NEED_VALUE;
    static const float HUMAN_SHELTER_DEFAULT_NEED_VALUE;
    static const float HUMAN_REPRODUCTION_DEFAULT_NEED_VALUE;
    static const float NEEDS_INFO_TEXT_SIZE;
    static const float NEEDS_INFO_TEXT_SPACING;
    static const float HUMAN_PHYSIOLOGY_EPS;
    static const float HUMAN_LUNGS_DEFAULT_CAPACITY ;

// ZOMBI CONFIGS
    static const float ZOMBIE_HEALTH;
    static const float ZOMBIE_STRENGTH;
    static const float ZOMBIE_AGILITY;
    static const float ZOMBIE_HEARING_RADIUS;
    static const float ZOMBIE_ATTACK_RADIUS;
    static const float ZOMBIE_SPAWN_POSITION_X;
    static const float ZOMBIE_SPAWN_POSITION_Y;
    static const float ZOMBIE_DEFAULT_TARGET_POSITION_X;
    static const float ZOMBIE_DEFAULT_TARGET_POSITION_Y;
    
// OTHERS
    static const float SOUND_MIN_RADIUS;
    static const float SOUND_MAX_RADIUS;
    static const float SOUND_RADIUS_STEP;

    // const Color 

};

#endif // CONFIG_H
