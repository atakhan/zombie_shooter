// Config.cpp
#include "Config.h"
#include "core/Bootstrap.h"

// GAME CONFIGS
const char* Config::GAME_TITLE              = "Zombie RPG";
const char* Config::WINDOW_TITLE            = "Zombie RPG";
const int Config::WINDOW_WIDTH              = 1200;
const int Config::WINDOW_HEIGHT             = 883;
const float Config::MAP_CELL_WIDTH          = 32.0f;
const float Config::MAP_CELL_HEIGHT         = 32.0f;

// UI CONFIGS
const float Config::DEFAULT_FONT_SIZE       = 16.0f;
const float Config::DEFAULT_PADDING         = 0.0f;
const float Config::DEFAULT_LINE_SPACING    = 22.0f;
const float Config::DEFAULT_TEXT_SPACING    = 1.0f;
const Color Config::DEFAULT_UI_TEXT_COLOR   = GRAY_1_8;
const Color Config::DEFAULT_FONT_COLOR      = GRAY_6_8;

// STYLE CONFIGS
const Color Config::PLAYER_SPAWN_CELL_COLOR = BLUE_3_3;
const Color Config::TERRAIN_DEFAULT_COLOR   = GREEN_3_4;
const Color Config::PLAYER_COLOR            = RAYWHITE;
const Color Config::HUMAN_COLOR             = BLUE_3_8;
const Color Config::ZOMBIE_COLOR            = RED_3_8;
const Color Config::ATTACK_RADIUS_COLOR     = RED_7_2;
const Color Config::SOUND_RADIUS_COLOR      = GRAY_6_1;
const Color Config::SMELL_RADIUS_COLOR      = YELLOW_3_8;
const Color Config::PATH_COLOR              = GRAY_6_4;
const Color Config::TARGET_COLOR            = RED_3_4;

// WALL CONFIGS
const float Config::DEFAULT_WALL_HEALTH     = 100.0f;

// LOOT CONFIGS
const float Config::DEFAULT_LOOT_AMOUNT     = 10.0f;
const float Config::DEFAULT_LOOT_SPAWN_POSITION_X = 300.0f;
const float Config::DEFAULT_LOOT_SPAWN_POSITION_Y = 425.0f;
const float Config::FOOD_DEFAULT_SIZE       = 425.0f;

// PLAYER CONFIGS
const float Config::PLAYER_HEALTH = 8.0f;
const float Config::PLAYER_STRENGTH = 5.0f;
const float Config::PLAYER_AGILITY = 1.0f;
const float Config::PLAYER_WALK_COEF= 0.5f;
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
const size_t Config::ZOMBIES_COUNT = 3;
const float Config::ZOMBIE_HEALTH = 10.0f; // HP based on health
const float Config::ZOMBIE_STRENGTH = 0.5f; //  Attack based on strength
const float Config::ZOMBIE_AGILITY = 0.5f; //  Speed based on agility
const float Config::ZOMBIE_WALK_COEF = 0.5;
const float Config::ZOMBIE_RUN_COEF = 1.0f;
const float Config::ZOMBIE_HEARING_RADIUS = 100.0f;
const float Config::ZOMBIE_ATTACK_RADIUS = 20.0f;
const float Config::ZOMBIE_SPAWN_POSITION_X = 422.0f;
const float Config::ZOMBIE_SPAWN_POSITION_Y = 376.0f;
const float Config::ZOMBIE_DEFAULT_TARGET_POSITION_X = 500.0f;
const float Config::ZOMBIE_DEFAULT_TARGET_POSITION_Y = 503.0f;

// OTHER CONFIGS
const float Config::SOUND_MAX_RADIUS = 256.0f;
const float Config::SOUND_RADIUS_STEP = 4.0f;