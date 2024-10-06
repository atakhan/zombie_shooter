#include "SceneControlSystem.h"
#include <iostream>

void SceneControlSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Scene Control System Initialized" << std::endl;
}

void SceneControlSystem::Draw(std::vector<Entity*> *entities) {}

void SceneControlSystem::Update(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity->HasComponent<SceneComponent>()) {
            SceneComponent *scene = entity->GetComponent<SceneComponent>();
            std::cout << scene->title << std::endl;
        }
    }
    if (IsKeyReleased(KEY_Q)) {
        std::cout << "KEY Q PRESSED!" << std::endl;

    }
    
}
