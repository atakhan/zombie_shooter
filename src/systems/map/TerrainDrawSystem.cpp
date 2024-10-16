#include "TerrainDrawSystem.h"
#include <iostream>

void TerrainDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Draw System Initialized" << std::endl;
}

void TerrainDrawSystem::Update(std::vector<Entity*> *entities) {}

void TerrainDrawSystem::DrawSpawnMapColors(TerrainComponent* terrain, SpawnMapComponent *spawnMap, int x, int y) {
    Color cellColor = GRAY_6_4;
    if (spawnMap->map_[x][y] == 0) {  // NO SPAWN
        // cellColor = Config::PLAYER_SPAWN_CELL_COLOR;
    } else
    if (spawnMap->map_[x][y] == 1) {  // PLAYER SPAWN POINT
        cellColor = R0G0B3A1;
    } else
    if (spawnMap->map_[x][y] == 2) {  // ZOMBIE SPAWN POINT
        cellColor = R3G0B0A1;
    } else {
        // cellColor = R3G3B3A1;
    }
    DrawRectangle(
        x * terrain->cellHeight_, 
        y * terrain->cellWidth_, 
        terrain->cellWidth_, 
        terrain->cellHeight_,
        cellColor
    );
}
void TerrainDrawSystem::DrawWallsColors(TerrainComponent* terrain, WallsMapComponent *wallsMap, int x, int y) {
    if (wallsMap->map_[x][y] == 1) {  // WALL ISSET
        DrawRectangle(
            x * terrain->cellHeight_, 
            y * terrain->cellWidth_, 
            terrain->cellWidth_, 
            terrain->cellHeight_,
            R0G0B3A1
        );
    }
}

void TerrainDrawSystem::Draw(std::vector<Entity*> *entities) {
    
    for (auto& entity : *entities) {
        if (entity != nullptr) {
            if (entity->HasComponent<TerrainComponent>()) {
                TerrainComponent* terrain = entity->GetComponent<TerrainComponent>();
                SpawnMapComponent *spawnMap = entity->GetComponent<SpawnMapComponent>();
                WallsMapComponent *wallsMap = entity->GetComponent<WallsMapComponent>();
                
                for (size_t i = 0; i < terrain->height_; i++) {
                    for (size_t j = 0; j < terrain->width_; j++) {
                        DrawSpawnMapColors(terrain, spawnMap, i, j);
                        DrawWallsColors(terrain, wallsMap, i, j);
                    }
                }
                break;
            }
        }

    }
    
}

