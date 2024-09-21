// RenderSystem.cpp
#include "RenderSystem.h"
#include <iostream>

void RenderSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Render System Initialized" << std::endl;
}

void RenderSystem::Update(std::vector<Entity*> *entities) {
    // Обновление состояния для отрисовки
}

void RenderSystem::Draw(std::vector<Entity*> *entities) {
    std::cout << "Rendering Game Objects" << std::endl;
}
