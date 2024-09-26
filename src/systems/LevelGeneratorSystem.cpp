// LevelGeneratorSystem.cpp
#include "LevelGeneratorSystem.h"
#include <iostream>

void LevelGeneratorSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Level Generator System Initialized" << std::endl;
}

void LevelGeneratorSystem::Update(std::vector<Entity*> *entities) {
    Player* player = nullptr;
    for (const auto& entity : *entities) {
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
    }

    if (player) {
        
    }
}

