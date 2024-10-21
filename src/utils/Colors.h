#ifndef UTILS_COLORS_H
#define UTILS_COLORS_H

#include <raylib-cpp.hpp>

// RED PATTERN
#define R0G0B0A7  CLITERAL(Color){ 0, 0, 0, 255 } 
#define R1G0B0A7  CLITERAL(Color){ 32, 0, 0, 255 } 
#define R2G0B0A7  CLITERAL(Color){ 64, 0, 0, 255 } 
#define R3G0B0A1  CLITERAL(Color){ 92, 0, 0, 32 } 
#define R3G0B0A2  CLITERAL(Color){ 92, 0, 0, 64 } 
#define R3G0B0A3  CLITERAL(Color){ 92, 0, 0, 92 } 
#define R3G0B0A4  CLITERAL(Color){ 92, 0, 0, 128 } 
#define R3G0B0A5  CLITERAL(Color){ 92, 0, 0, 160 } 
#define R3G0B0A6  CLITERAL(Color){ 92, 0, 0, 192 } 
#define R3G0B0A7  CLITERAL(Color){ 92, 0, 0, 224 } 
#define R3G0B0A8  CLITERAL(Color){ 92, 0, 0, 255 } 
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

// GREEN PATTERN
#define R0G3B0A4  CLITERAL(Color){ 0, 92, 0, 128 }

// YELLOW PATTERN
#define R1G1B0A8  CLITERAL(Color){ 32, 32, 0, 255 }
#define R2G2B0A8  CLITERAL(Color){ 64, 64, 0, 255 }
#define R3G3B0A8  CLITERAL(Color){ 92, 92, 0, 255 }
#define R4G4B0A8  CLITERAL(Color){ 128, 128, 0, 255 }
#define R5G5B0A8  CLITERAL(Color){ 160, 160, 0, 255 }
#define R6G6B0A8  CLITERAL(Color){ 192, 192, 0, 255 }
#define R7G7B0A3  CLITERAL(Color){ 224, 224, 0, 92 }
#define R7G7B0A8  CLITERAL(Color){ 224, 224, 0, 255 }
#define R8G8B0A8  CLITERAL(Color){ 255, 255, 0, 255 }

// BLUE PATTERN
#define R0G0B0A7  CLITERAL(Color){ 0, 0, 0, 255 } 
#define R0G0B1A7  CLITERAL(Color){ 0, 0, 32, 255 } 
#define R0G0B2A7  CLITERAL(Color){ 0, 0, 64, 255 } 
#define R0G0B3A1  CLITERAL(Color){ 0, 0, 92, 32 } 
#define R0G0B3A2  CLITERAL(Color){ 0, 0, 92, 64 } 
#define R0G0B3A3  CLITERAL(Color){ 0, 0, 92, 92 } 
#define R0G0B3A4  CLITERAL(Color){ 0, 0, 92, 128 } 
#define R0G0B3A5  CLITERAL(Color){ 0, 0, 92, 160 } 
#define R0G0B3A6  CLITERAL(Color){ 0, 0, 92, 192 } 
#define R0G0B3A7  CLITERAL(Color){ 0, 0, 92, 224 } 
#define R0G0B3A8  CLITERAL(Color){ 0, 0, 92, 255 } 
#define R0G0B4A8  CLITERAL(Color){ 0, 0, 128, 255 } 
#define R0G0B5A8  CLITERAL(Color){ 0, 0, 160, 255 } 
#define R0G0B6A8  CLITERAL(Color){ 0, 0, 192, 255 } 
#define R0G0B7A8  CLITERAL(Color){ 0, 0, 255, 255 }

// GRAY PATTERN
#define R3G3B3A1  CLITERAL(Color){ 92, 92, 92, 32 } 
#define R5G5B5A05  CLITERAL(Color){ 160, 160, 160, 16 } 
#define R6G6B6A1  CLITERAL(Color){ 192, 192, 192, 32 } 
#define R6G6B6A2  CLITERAL(Color){ 192, 192, 192, 64 } 
#define R6G6B6A3  CLITERAL(Color){ 192, 192, 192, 92 } 
#define R6G6B6A4  CLITERAL(Color){ 192, 192, 192, 128 } 
#define R6G6B6A5  CLITERAL(Color){ 192, 192, 192, 160 } 
#define R6G6B6A6  CLITERAL(Color){ 192, 192, 192, 192 } 
#define R6G6B6A7  CLITERAL(Color){ 192, 192, 192, 224 } 
#define R6G6B6A8  CLITERAL(Color){ 192, 192, 192, 255 } 
#define R8G8B8A1  CLITERAL(Color){ 255, 255, 255, 32 } 
#define R8G8B8A8  CLITERAL(Color){ 255, 255, 255, 255 } 
#define R1G1B1A1  CLITERAL(Color){ 32, 32, 32, 32 } 
#define R1G1B1A2  CLITERAL(Color){ 32, 32, 32, 64 } 
#define R1G1B1A3  CLITERAL(Color){ 32, 32, 32, 92 } 
#define R1G1B1A4  CLITERAL(Color){ 32, 32, 32, 128 } 
#define R1G1B1A5  CLITERAL(Color){ 32, 32, 32, 160 } 
#define R1G1B1A6  CLITERAL(Color){ 32, 32, 32, 192 } 
#define R1G1B1A7  CLITERAL(Color){ 32, 32, 32, 224 } 
#define R1G1B1A8  CLITERAL(Color){ 32, 32, 32, 255 } 

#define YELLOW_3_8  R3G3B0A8
#define BLUE_3_3    R0G0B3A3
#define BLUE_3_8    R0G0B3A8
#define RED_3_8     R3G0B0A8
#define RED_7_2     R7G0B0A2
#define GRAY_5_05   R5G5B5A05
#define GRAY_6_1    R6G6B6A1
#define GRAY_6_2    R6G6B6A2
#define GRAY_6_4    R6G6B6A4
#define GRAY_6_8    R6G6B6A8
#define GRAY_8_8    R8G8B8A8
#define GRAY_1_8    R1G1B1A8
#define RED_3_4     R3G0B0A4
#define GREEN_3_4   R0G3B0A4


#endif // UTILS_COLORS_H