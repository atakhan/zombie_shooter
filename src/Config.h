// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <raylib-cpp.hpp>

#define R0G0B0A7  CLITERAL(Color){ 0, 0, 0, 255 } 
#define R1G0B0A7  CLITERAL(Color){ 32, 0, 0, 255 } 
#define R2G0B0A7  CLITERAL(Color){ 64, 0, 0, 255 } 
#define R3G0B0A1  CLITERAL(Color){ 92, 0, 0, 32 } 
#define R3G0B0A2  CLITERAL(Color){ 92, 0, 0, 64 } 
#define R3G0B0A3  CLITERAL(Color){ 92, 0, 0, 92 } 
#define R3G0B0A4  CLITERAL(Color){ 92, 0, 0, 128 } 
#define R3G0B0A5  CLITERAL(Color){ 92, 0, 0, 160 } 
#define R3G0B0A6  CLITERAL(Color){ 92, 0, 0, 192 } 
#define R3G0B0A7  CLITERAL(Color){ 92, 0, 0, 255 } 
#define R4G0B0A7  CLITERAL(Color){ 128, 0, 0, 255 } 
#define R5G0B0A7  CLITERAL(Color){ 160, 0, 0, 255 } 
#define R6G0B0A7  CLITERAL(Color){ 192, 0, 0, 255 } 
#define R7G0B0A1  CLITERAL(Color){ 255, 0, 0, 32 }
#define R7G0B0A2  CLITERAL(Color){ 255, 0, 0, 64 }
#define R7G0B0A3  CLITERAL(Color){ 255, 0, 0, 92 }
#define R7G0B0A4  CLITERAL(Color){ 255, 0, 0, 128 }
#define R7G0B0A5  CLITERAL(Color){ 255, 0, 0, 160 }
#define R7G0B0A6  CLITERAL(Color){ 255, 0, 0, 192 }
#define R7G0B0A7  CLITERAL(Color){ 255, 0, 0, 255 }


#define R0G0B0A7  CLITERAL(Color){ 0, 0, 0, 255 } 
#define R0G0B1A7  CLITERAL(Color){ 0, 0, 32, 255 } 
#define R0G0B2A7  CLITERAL(Color){ 0, 0, 64, 255 } 
#define R0G0B3A1  CLITERAL(Color){ 0, 0, 92, 32 } 
#define R0G0B3A2  CLITERAL(Color){ 0, 0, 92, 64 } 
#define R0G0B3A3  CLITERAL(Color){ 0, 0, 92, 92 } 
#define R0G0B3A4  CLITERAL(Color){ 0, 0, 92, 128 } 
#define R0G0B3A5  CLITERAL(Color){ 0, 0, 92, 160 } 
#define R0G0B3A6  CLITERAL(Color){ 0, 0, 92, 192 } 
#define R0G0B3A7  CLITERAL(Color){ 0, 0, 92, 255 } 
#define R0G0B4A7  CLITERAL(Color){ 0, 0, 128, 255 } 
#define R0G0B5A7  CLITERAL(Color){ 0, 0, 160, 255 } 
#define R0G0B6A7  CLITERAL(Color){ 0, 0, 192, 255 } 
#define R0G0B7A7  CLITERAL(Color){ 0, 0, 255, 255 }

#define R6G6B6A1  CLITERAL(Color){ 192, 192, 192, 32 } 
#define R6G6B6A2  CLITERAL(Color){ 192, 192, 192, 64 } 
#define R6G6B6A3  CLITERAL(Color){ 192, 192, 192, 92 } 
#define R6G6B6A4  CLITERAL(Color){ 192, 192, 192, 128 } 
#define R6G6B6A5  CLITERAL(Color){ 192, 192, 192, 160 } 
#define R6G6B6A6  CLITERAL(Color){ 192, 192, 192, 192 } 

class Config {
public:
// GAME CONFIGS
    static const std::string WINDOW_TITLE;
    static const int WINDOW_WIDTH;
    static const int WINDOW_HEIGHT;
    static const size_t ZOMBIES_COUNT;
    static const float WALK_COEF;
    static const float RUN_COEF;
    
// PLAYER CONFIGS
    static const Color PLAYER_COLOR;
    static const float PLAYER_HEALTH;
    static const float PLAYER_STRENGTH;
    static const float PLAYER_AGILITY;
    static const float PLAYER_HEARING_RADIUS;
    static const float PLAYER_ATTACK_RADIUS;
    static const float PLAYER_SPAWN_POSITION_X;
    static const float PLAYER_SPAWN_POSITION_Y;

// PLAYER CONFIGS
    static const Color ZOMBIE_COLOR;
    static const float ZOMBIE_HEALTH;
    static const float ZOMBIE_STRENGTH;
    static const float ZOMBIE_AGILITY;
    static const float ZOMBIE_HEARING_RADIUS;
    static const float ZOMBIE_ATTACK_RADIUS;
    static const float ZOMBIE_SPAWN_POSITION_X;
    static const float ZOMBIE_SPAWN_POSITION_Y;
    
// OTHERS
    static const Color ATTACK_RADIUS_COLOR;
    static const Color SOUND_RADIUS_COLOR;
    static const Color PATH_COLOR;
    static const Color GOAL_COLOR;
    static const float SOUND_MIN_RADIUS;
    static const float SOUND_MAX_RADIUS;
    static const float SOUND_RADIUS_STEP;

    // const Color 

};

#endif // CONFIG_H
