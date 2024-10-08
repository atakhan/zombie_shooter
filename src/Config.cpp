// Config.cpp
#include "Config.h"

// GAME CONFIGS
const char* Config::GAME_TITLE = "Zombie RPG";
const int Config::WINDOW_WIDTH = 1200;
const int Config::WINDOW_HEIGHT = 883;
const size_t Config::ZOMBIES_COUNT = 100;
const float Config::DEFAULT_LOOT_AMOUNT = 10.0f;
const float Config::DEFAULT_LOOT_SPAWN_POSITION_X = 300.0f;
const float Config::DEFAULT_LOOT_SPAWN_POSITION_Y = 425.0f;
const float Config::FOOD_DEFAULT_SIZE = 425.0f;

// UI CONFIGS
const float Config::DEFAULT_FONT_SIZE = 16.0f;
const float Config::DEFAULT_PADDING = 0.0f;
const float Config::DEFAULT_LINE_SPACING = 22.0f;
const float Config::DEFAULT_TEXT_SPACING = 1.0f;
const float Config::TITLE_VALUE_LIST_TEXT_SIZE = 16.0f;
const float Config::TITLE_VALUE_LIST_TEXT_SPACING = 1.0f;
const Color Config::DEFAULT_UI_TEXT_COLOR = GRAY_1_8;
const Color Config::DEFAULT_FONT_COLOR = GRAY_6_8;

// STYLE CONFIGS
const Color Config::TERRAIN_DEFAULT_COLOR   = GREEN_3_4;
const Color Config::PLAYER_COLOR            = BLUE_3_8;
const Color Config::HUMAN_COLOR             = BLUE_3_8;
const Color Config::ZOMBIE_COLOR            = RED_3_8;
const Color Config::ATTACK_RADIUS_COLOR     = RED_7_2;
const Color Config::SOUND_RADIUS_COLOR      = GRAY_6_2;
const Color Config::SMELL_RADIUS_COLOR      = YELLOW_3_8;
const Color Config::PATH_COLOR              = GRAY_6_4;
const Color Config::TARGET_COLOR            = RED_3_4;

// PLAYER CONFIGS
const float Config::PLAYER_HEALTH = 20.0f;
const float Config::PLAYER_STRENGTH = 10.0f;
const float Config::PLAYER_AGILITY = 2.0f;
const float Config::PLAYER_WALK_COEF= 1.0f;
const float Config::PLAYER_RUN_COEF= 3.0f;
const float Config::PLAYER_HEARING_RADIUS = 100.0f;
const float Config::PLAYER_ATTACK_RADIUS = 20.0f;
const float Config::PLAYER_SPAWN_POSITION_X = 600.0f;
const float Config::PLAYER_SPAWN_POSITION_Y = 673.0f;

// HUMAN CONFIGS
const float Config::HUMAN_DEFAULT_HEALTH = 20.0f;
const float Config::HUMAN_DEFAULT_STRENGTH = 10.0f;
const float Config::HUMAN_DEFAULT_AGILITY = 2.0f;
const float Config::HUMAN_DEFAULT_STAMINA = 100.0f;
const float Config::HUMAN_WALK_COEF= 1.0f;
const float Config::HUMAN_RUN_COEF= 3.0f;
const float Config::HUMAN_HEARING_RADIUS = 100.0f;
const float Config::HUMAN_ATTACK_RADIUS = 20.0f;
const float Config::HUMAN_SPAWN_POSITION_X = 500.0f;
const float Config::HUMAN_SPAWN_POSITION_Y = 473.0f;
const float Config::HUMAN_DEFAULT_TARGET_X = 300.0f;
const float Config::HUMAN_DEFAULT_TARGET_Y = 425.0f;
const float Config::HUMAN_MOVE_TRESHOLD = 1.0f;

// ZOMBIE CONFIGS
const float Config::ZOMBIE_HEALTH = 10.0f; // HP based on health
const float Config::ZOMBIE_STRENGTH = 0.5f; //  Attack based on strength
const float Config::ZOMBIE_AGILITY = 1.0f; //  Speed based on agility
const float Config::ZOMBIE_WALK_COEF = 0.2;
const float Config::ZOMBIE_RUN_COEF = 1;
const float Config::ZOMBIE_HEARING_RADIUS = 100.0f;
const float Config::ZOMBIE_ATTACK_RADIUS = 20.0f;
const float Config::ZOMBIE_SPAWN_POSITION_X = 122.0f;
const float Config::ZOMBIE_SPAWN_POSITION_Y = 66.0f;
const float Config::ZOMBIE_DEFAULT_TARGET_POSITION_X = 300.0f;
const float Config::ZOMBIE_DEFAULT_TARGET_POSITION_Y = 303.0f;

// OTHER CONFIGS
const float Config::SOUND_MAX_RADIUS = 256.0f;
const float Config::SOUND_RADIUS_STEP = 4.0f;