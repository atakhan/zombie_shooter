// Scene.cpp
#include "Scene.h"

void Scene::UpdateCamera() {
    Player* player = nullptr;
    for (const auto& entity : entities_) {
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
    }
    if (player && camera_) {
        camera_->target = (Vector2){ 
            player->GetPositionX() + 20, 
            player->GetPositionY() + 20
        };
    }
}

void Scene::InitCamera() {
    camera_->target = (Vector2) {
        Config::PLAYER_SPAWN_POSITION_X + 20.0f,
        Config::PLAYER_SPAWN_POSITION_Y + 20.0f
    };
    camera_->offset = (Vector2) {
        Config::WINDOW_WIDTH / 2.0f,
        Config::WINDOW_HEIGHT / 2.0f
    };
    camera_->rotation = 0.0f;
    camera_->zoom = 1.0f;
}

void Scene::Init() {
    InitCamera();
    for (auto& system : systems_) {
        system->Init(&entities_);
    }
}
void Scene::Update() {
    UpdateCamera();
    UpdateSystems();
}
void Scene::Draw() {
    BeginMode2D(*camera_);
    DrawEntities();
    EndMode2D();
}

void Scene::AddCamera(Camera2D* camera) {
    camera_ = camera;
}

void Scene::AddSystem(System* system) {
    systems_.push_back(system);
}
void Scene::RemoveSystem(System* system) {
    systems_.erase(std::remove(systems_.begin(), systems_.end(), system), systems_.end());
    delete system; // Освобождаем память
}
void Scene::UpdateSystems() {
    for (auto& system : systems_) {
        system->Update(&entities_);
    }
}

void Scene::AddEntity(Entity* entity) {
    entities_.push_back(entity);
}
void Scene::RemoveEntity(Entity* entity) {
    entities_.erase(std::remove(entities_.begin(), entities_.end(), entity), entities_.end());
    delete entity; // Освобождаем память
}

void Scene::DrawEntities() {
    for (auto& entity : entities_) {
        entity->Draw();
    }
}
