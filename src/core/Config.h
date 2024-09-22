// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <raylib-cpp.hpp>

#define R0G0B0A7  CLITERAL(Color){ 0, 0, 0, 255 } 
#define R1G0B0A7  CLITERAL(Color){ 32, 0, 0, 255 } 
#define R2G0B0A7  CLITERAL(Color){ 64, 0, 0, 255 } 
#define R3G0B0A7  CLITERAL(Color){ 92, 0, 0, 255 } 
#define R4G0B0A7  CLITERAL(Color){ 128, 0, 0, 255 } 
#define R5G0B0A7  CLITERAL(Color){ 160, 0, 0, 255 } 
#define R6G0B0A7  CLITERAL(Color){ 192, 0, 0, 255 } 
#define R7G0B0A7  CLITERAL(Color){ 255, 0, 0, 255 }

#define R6G6B6A6  CLITERAL(Color){ 192, 192, 192, 192 } 

class Config {
public:
// GAME CONFIGS
    static const std::string WINDOW_TITLE;
    static const int WINDOW_WIDTH;
    static const int WINDOW_HEIGHT;
    
// PLAYER CONFIGS
    static const Color PLAYER_COLOR;
    
// OTHERS
    static const Color SOUND_RADIUS_COLOR;

    // const Color 

};

#endif // CONFIG_H
