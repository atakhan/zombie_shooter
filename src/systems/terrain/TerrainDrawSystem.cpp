#include "TerrainDrawSystem.h"
#include <iostream>

void TerrainDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Draw System Initialized" << std::endl;
}

void TerrainDrawSystem::Update(std::vector<Entity*> *entities) {}

void TerrainDrawSystem::Draw(std::vector<Entity*> *entities) {
    
    for (auto& entity : *entities) {
        if (entity != nullptr) {
            if (entity->HasComponent<TerrainComponent>()) {
                TerrainComponent* terrain = entity->GetComponent<TerrainComponent>();
                for (size_t i = 0; i < terrain->height_; i++)
                {
                    for (size_t j = 0; j < terrain->width_; j++)
                    {
                        DrawRectangle(
                            i * terrain->cellHeight_, 
                            j * terrain->cellWidth_, 
                            terrain->cellWidth_, 
                            terrain->cellHeight_,
                            Config::TERRAIN_DEFAULT_COLOR
                        );
                        DrawRectangle(
                            (i * terrain->cellHeight_) + 2, 
                            (j * terrain->cellWidth_) + 2, 
                            terrain->cellWidth_ - 2, 
                            terrain->cellHeight_ - 2,
                            Config::ATTACK_RADIUS_COLOR
                        );
                    }
                }
                
            }
        }

    }
    
}

