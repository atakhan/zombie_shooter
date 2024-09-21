// ZombieSystem.cpp
#include "ZombieSystem.h"
#include <iostream>

void ZombieSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie System Initialized" << std::endl;
}

void ZombieSystem::Update(std::vector<Entity*> *entities) {
    std::cout << "Updating Zombie System" << std::endl;
    // Логика появления и движения зомби
}

void ZombieSystem::Draw(std::vector<Entity*> *entities) {
    std::cout << "Drawing Zombies" << std::endl;
}
