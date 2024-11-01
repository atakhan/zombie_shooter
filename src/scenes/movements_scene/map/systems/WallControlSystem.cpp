#include "WallControlSystem.h"
#include <iostream>

void WallControlSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Wall Control System Initialized" << std::endl;
}

void WallControlSystem::Update(std::vector<Entity*> *entities) {}

void WallControlSystem::Draw(std::vector<Entity*> *entities) {
    
    for (auto& entity : *entities) {
        if (entity != nullptr) {
            if (entity->HasComponent<TerrainComponent>()) {
                TerrainComponent* terrain = entity->GetComponent<TerrainComponent>();
                SpawnMapComponent *spawnMap = entity->GetComponent<SpawnMapComponent>();
                WallsMapComponent *wallsMap = entity->GetComponent<WallsMapComponent>();
                
                for (size_t y = 0; y < terrain->height_; y++) {
                    for (size_t x = 0; x < terrain->width_; x++) {
                        DrawSpawnMapColors(terrain, spawnMap, x, y);
                        DrawWallsColors(terrain, wallsMap, x, y);
                        DrawFloorColors(terrain, wallsMap, x, y);
                    }
                }
                break;
            }
        }

    }
    
}

void WallControlSystem::DrawSpawnMapColors(TerrainComponent* terrain, SpawnMapComponent *spawnMap, int x, int y) {
    if (spawnMap->map_[y][x] == 1) {  // PLAYER SPAWN POINT
        DrawRectangle(
            x * terrain->cellWidth_, 
            y * terrain->cellHeight_,
            terrain->cellWidth_, 
            terrain->cellHeight_,
            R0G0B3A1
        );
    } else
    if (spawnMap->map_[y][x] == 2) {  // ZOMBIE SPAWN POINT
        DrawRectangle(
            x * terrain->cellWidth_, 
            y * terrain->cellHeight_,
            terrain->cellWidth_, 
            terrain->cellHeight_,
            R3G0B0A1
        );
    }
}
void WallControlSystem::DrawWallsColors(TerrainComponent* terrain, WallsMapComponent *wallsMap, int x, int y) {
    if (wallsMap->map_[y][x] == 1) {  // WALL ISSET
        DrawRectangle(
            x * terrain->cellWidth_, 
            y * terrain->cellHeight_, 
            terrain->cellWidth_, 
            terrain->cellHeight_,
            R1G1B1A2
        );
    }
}
void WallControlSystem::DrawFloorColors(TerrainComponent* terrain, WallsMapComponent *wallsMap, int x, int y) {
    if (wallsMap->map_[y][x] == 0) {  // WALL NOT ISSET
        DrawRectangle(
            x * terrain->cellWidth_, 
            y * terrain->cellHeight_, 
            terrain->cellWidth_, 
            terrain->cellHeight_,
            R1G1B1A4
        );
    }
}