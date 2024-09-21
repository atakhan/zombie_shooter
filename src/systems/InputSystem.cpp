// InputSystem.cpp
#include "InputSystem.h"
#include <iostream>

void InputSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Input System Initialized" << std::endl;
}

void InputSystem::Update(std::vector<Entity*> *entities) {
    std::cout << "Updating Input System" << std::endl;
    // Здесь добавьте обработку ввода (например, стрельба)
}

void InputSystem::Draw(std::vector<Entity*> *entities) {
    std::cout << "Drawing Input System" << std::endl;
}
