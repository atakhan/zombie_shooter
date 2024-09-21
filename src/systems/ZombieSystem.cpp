// ZombieSystem.cpp
#include "ZombieSystem.h"
#include <iostream>

void ZombieSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie System Initialized" << std::endl;
}

void ZombieSystem::Update(std::vector<Entity*> *entities) {
    for (Entity* entity : *entities) {
        Zombie* zombie = dynamic_cast<Zombie*>(entity);
        if (zombie) {
            zombie->Update();
        }
    }
}

void ZombieSystem::Draw(std::vector<Entity*> *entities) {
    std::cout << "Drawing Zombies" << std::endl;
}
