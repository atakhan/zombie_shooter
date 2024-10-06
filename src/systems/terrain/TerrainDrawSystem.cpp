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
                DrawRectangle(0,0,terrain->width_,terrain->height_,Config::TERRAIN_DEFAULT_COLOR);
            }
        }

    }
    
}

