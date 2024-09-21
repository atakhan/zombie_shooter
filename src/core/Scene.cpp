// Scene.cpp
#include "Scene.h"
#include <algorithm>
#include <iostream>

void Scene::Init() {
    
}
void Scene::Update() {
    UpdateSystems();
}
void Scene::Draw() {
    DrawEntities();
}

void Scene::AddSystem(System* system) {
    systems.push_back(system);
}
void Scene::RemoveSystem(System* system) {
    systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
    delete system; // Освобождаем память
}
void Scene::UpdateSystems() {
    for (auto& system : systems) {
        system->Update(&entities);
    }
}

void Scene::AddEntity(Entity* entity) {
    entities.push_back(entity);
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
