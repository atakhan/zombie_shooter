// Scene.cpp
#include "Scene.h"

void Scene::Init() {
    for (auto& system : systems_) {
        system->Init(&entities_);
    }
}

void Scene::AddSystem(System* system) {
    systems_.push_back(system);
}
void Scene::RemoveSystem(System* system) {
    systems_.erase(std::remove(systems_.begin(), systems_.end(), system), systems_.end());
    delete system; // Освобождаем память
}

void Scene::AddEntity(Entity* entity) {
    entities_.push_back(entity);
}
void Scene::RemoveEntity(Entity* entity) {
    entities_.erase(std::remove(entities_.begin(), entities_.end(), entity), entities_.end());
    delete entity; // Освобождаем память
}
// void Scene::DrawEntities() {
//     for (auto& entity : entities_) {
//         entity->Draw();
//     }
// }
