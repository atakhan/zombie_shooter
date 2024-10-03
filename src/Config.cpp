// Config.cpp
#include "Config.h"

// STYLE CONFIGS
const Color Config::SMELL_RADIUS_COLOR      = YELLOW_3_8;
const Color Config::PLAYER_COLOR            = BLUE_3_8;
const Color Config::HUMAN_COLOR             = BLUE_3_8;
const Color Config::ZOMBIE_COLOR            = RED_3_8;
const Color Config::ATTACK_RADIUS_COLOR     = RED_7_2;
const Color Config::SOUND_RADIUS_COLOR      = GREY_6_2;
const Color Config::PATH_COLOR              = GREY_6_4;
const Color Config::GOAL_COLOR              = RED_3_4;
const Color Config::NEEDS_INFO_TEXT_COLOR   = GREY_1_8;

// GAME CONFIGS
const char * Config::WINDOW_TITLE = "Zombie RPG";
const int Config::WINDOW_WIDTH = 610;
const int Config::WINDOW_HEIGHT = 683;
const size_t Config::ZOMBIES_COUNT = 100;
const float Config::DEFAULT_LOOT_AMOUNT = 10.0f;
const float Config::DEFAULT_LOOT_SPAWN_POSITION_X = 300.0f;
const float Config::DEFAULT_LOOT_SPAWN_POSITION_Y = 425.0f;
const float Config::FOOD_DEFAULT_SIZE = 425.0f;

// PLAYER CONFIGS
const float Config::PLAYER_HEALTH = 20.0f;
const float Config::PLAYER_STRENGTH = 10.0f;
const float Config::PLAYER_AGILITY = 2.0f;
const float Config::PLAYER_HEARING_RADIUS = 100.0f;
const float Config::PLAYER_ATTACK_RADIUS = 20.0f;
const float Config::PLAYER_SPAWN_POSITION_X = 600.0f;
const float Config::PLAYER_SPAWN_POSITION_Y = 673.0f;

// HUMAN CONFIGS
const float Config::HUMAN_HEALTH = 20.0f;
const float Config::HUMAN_STRENGTH = 10.0f;
const float Config::HUMAN_AGILITY = 2.0f;
const float Config::HUMAN_WALK_SPEED= 1.0f;
const float Config::HUMAN_RUN_SPEED= 3.0f;
const float Config::HUMAN_HEARING_RADIUS = 100.0f;
const float Config::HUMAN_ATTACK_RADIUS = 20.0f;
const float Config::HUMAN_SPAWN_POSITION_X = 500.0f;
const float Config::HUMAN_SPAWN_POSITION_Y = 473.0f;
const float Config::HUMAN_DEFAULT_TARGET_X = 300.0f;
const float Config::HUMAN_DEFAULT_TARGET_Y = 425.0f;
const float Config::HUMAN_MOVE_TRESHOLD = 1.0f;
const float Config::NEEDS_INFO_TEXT_SIZE = 16.0f;
const float Config::NEEDS_INFO_TEXT_SPACING = 1.0f;
const float Config::HUMAN_PHYSIOLOGY_EPS = 0.01f;
const float Config::HUMAN_LUNGS_DEFAULT_CAPACITY = 10.0f;

// HUMAN NEEDS DEFAULT CONFIGS
const float Config::HUMAN_AIR_DEFAULT_NEED_VALUE =100.0f;
const float Config::HUMAN_WATER_DEFAULT_NEED_VALUE =100.0f;
const float Config::HUMAN_FOOD_DEFAULT_NEED_VALUE =100.0f;
const float Config::HUMAN_HEAT_DEFAULT_NEED_VALUE =100.0f;
const float Config::HUMAN_CLOTHES_DEFAULT_NEED_VALUE =100.0f;
const float Config::HUMAN_SLEEP_DEFAULT_NEED_VALUE =100.0f;
const float Config::HUMAN_SHELTER_DEFAULT_NEED_VALUE =100.0f;
const float Config::HUMAN_REPRODUCTION_DEFAULT_NEED_VALUE =100.0f;

// ZOMBIE CONFIGS
const float Config::ZOMBIE_HEALTH = 10.0f; // HP based on health
const float Config::ZOMBIE_STRENGTH = 0.5f; //  Attack based on strength
const float Config::ZOMBIE_AGILITY = 0.5f;
const float Config::WALK_COEF = 0.2;
const float Config::RUN_COEF = 1;
const float Config::ZOMBIE_HEARING_RADIUS = 100.0f;
const float Config::ZOMBIE_ATTACK_RADIUS = 20.0f;
const float Config::ZOMBIE_SPAWN_POSITION_X = 122.0f;
const float Config::ZOMBIE_SPAWN_POSITION_Y = 66.0f;
const float Config::ZOMBIE_DEFAULT_TARGET_POSITION_X = 600.0f;
const float Config::ZOMBIE_DEFAULT_TARGET_POSITION_Y = 673.0f;

// OTHER CONFIGS
const float Config::SOUND_MIN_RADIUS = 50.0f;
const float Config::SOUND_MAX_RADIUS = 100.0f;
const float Config::SOUND_RADIUS_STEP = 4.0f;