// Scene.cpp
#include "Scene.h"

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

void Scene::HandleExit(int *currentSceneIndex) {
    if (IsKeyDown(KEY_Q)) {
        if (*currentSceneIndex == 0) {
            continue_ = false;
        } else {
            continue_ = false;
            *currentSceneIndex = 0;
            scenes_->at(0)->continue_ = true;
        }
    }
}

void Scene::SetSceneList(std::vector<Scene*> *scenes) {
    scenes_ = scenes;
}

std::string Scene::GetTitle() {
    return title_;
}
