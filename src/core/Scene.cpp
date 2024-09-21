// Scene.cpp
#include "Scene.h"
#include <algorithm>
#include <iostream>

void Scene::AddEntity(Entity* entity) {
    entities.push_back(entity);
}

void Scene::UpdateEntities(float playerX, float playerY) {
    for (auto& entity : entities) {
        entity->Update(playerX, playerY);
    }
}

void Scene::RemoveEntity(Entity* entity) {
    entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
    delete entity; // Освобождаем память
}

void Scene::DrawEntities() {
    for (auto& entity : entities) {
        entity->Draw();
    }
}
