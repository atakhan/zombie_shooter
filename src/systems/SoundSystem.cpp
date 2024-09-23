// PlayerSystem.cpp
#include "SoundSystem.h"
#include <iostream>

void SoundSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Input System Initialized" << std::endl;
}

void SoundSystem::Update(std::vector<Entity*> *entities) {
    for (const auto& entity : *entities) {
        Player* player = nullptr;
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
        if (player) {
            
        }
    }
}

