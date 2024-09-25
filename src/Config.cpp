// Config.cpp
#include "Config.h"

// GAME CONFIGS
const std::string Config::WINDOW_TITLE = "Zombie RPG";
const int Config::WINDOW_WIDTH = 610;
const int Config::WINDOW_HEIGHT = 683;
const size_t Config::ZOMBIES_COUNT = 10;

// PLAYER CONFIGS
const Color Config::PLAYER_COLOR = R0G0B5A7;
const float Config::PLAYER_HEALTH = 20.0f;
const float Config::PLAYER_STRENGTH = 10.0f;
const float Config::PLAYER_AGILITY = 2.0f;
const float Config::PLAYER_HEARING_RADIUS = 100.0f;
const float Config::PLAYER_ATTACK_RADIUS = 20.0f;
const float Config::PLAYER_SPAWN_POSITION_X = 600.0f;
const float Config::PLAYER_SPAWN_POSITION_Y = 673.0f;

// ZOMBIE CONFIGS
const Color Config::ZOMBIE_COLOR = R5G0B0A7;
const float Config::ZOMBIE_HEALTH = 10.0f; // HP based on health
const float Config::ZOMBIE_STRENGTH = 25.0f; //  Attack based on strength
const float Config::ZOMBIE_AGILITY = 0.5f;
const float Config::WALK_COEF = 0.2;
const float Config::RUN_COEF = 1;
const float Config::ZOMBIE_HEARING_RADIUS = 100.0f;
const float Config::ZOMBIE_ATTACK_RADIUS = 20.0f;
const float Config::ZOMBIE_SPAWN_POSITION_X = 122.0f;
const float Config::ZOMBIE_SPAWN_POSITION_Y = 66.0f;

// OTHER CONFIGS
const Color Config::SOUND_RADIUS_COLOR = R6G6B6A2;
const Color Config::PATH_COLOR = R6G6B6A4;
const Color Config::GOAL_COLOR = R3G0B0A4;
const float Config::SOUND_MIN_RADIUS = 50.0f;
const float Config::SOUND_MAX_RADIUS = 100.0f;
const float Config::SOUND_RADIUS_STEP = 4.0f;