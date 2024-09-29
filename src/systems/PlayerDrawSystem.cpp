#include "PlayerDrawSystem.h"
#include <iostream>

void PlayerDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Player Draw System Initialized" << std::endl;
}

void PlayerDrawSystem::Update(std::vector<Entity*> *entities) {}

void PlayerDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (const auto& entity : *entities) {
        Player* player = nullptr;
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
        if (player) {
            
        }
    }
}

