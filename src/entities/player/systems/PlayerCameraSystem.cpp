#include "PlayerCameraSystem.h"
#include <iostream>

void PlayerCameraSystem::Init(std::vector<Entity*> *entities) {

    Entity *playerEntity = GetEntityByComponent<PlayerComponent>(entities);
    if (playerEntity == nullptr) { return; }

    CameraComponent *camera = playerEntity->GetComponent<CameraComponent>();
    PlayerBodyComponent *playerBody = playerEntity->GetComponent<PlayerBodyComponent>();
    
    if (playerBody) {
        camera->camera_.target = (Vector2) {
            playerBody->pos_.x + 20.0f,
            playerBody->pos_.y + 20.0f
        };
        camera->camera_.offset = (Vector2) {
            Config::WINDOW_WIDTH / 2.0f,
            Config::WINDOW_HEIGHT / 2.0f
        };
        camera->camera_.rotation = 0.0f;
        camera->camera_.zoom = 1.0f;
    }

}

void PlayerCameraSystem::Update(std::vector<Entity*> *entities) {
    Entity *playerEntity = GetEntityByComponent<PlayerComponent>(entities);
    if (playerEntity == nullptr) { return; }

    PlayerBodyComponent *playerBody = playerEntity->GetComponent<PlayerBodyComponent>();
    CameraComponent *camera = playerEntity->GetComponent<CameraComponent>();
    
    if (playerBody && camera) {
        camera->camera_.target = (Vector2){ 
            playerBody->pos_.x + 20.0f, 
            playerBody->pos_.y + 20.0f
        };
    }
}

void PlayerCameraSystem::Draw(std::vector<Entity*> *entities) {

}

