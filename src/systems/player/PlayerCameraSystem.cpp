#include "PlayerCameraSystem.h"
#include <iostream>

void PlayerCameraSystem::Init(std::vector<Entity*> *entities) {

    Entity *playerEntity = GetEntityByComponent<PlayerComponent>(entities);
    if (playerEntity == nullptr) { return; }

    CameraComponent *camera = playerEntity->GetComponent<CameraComponent>();
    PositionComponent *playerPosition = playerEntity->GetComponent<PositionComponent>();
    
    camera->camera_.target = (Vector2) {
        playerPosition->position_.x + 20.0f,
        playerPosition->position_.y + 20.0f
    };
    camera->camera_.offset = (Vector2) {
        Config::WINDOW_WIDTH / 2.0f,
        Config::WINDOW_HEIGHT / 2.0f
    };
    camera->camera_.rotation = 0.0f;
    camera->camera_.zoom = 1.0f;
}

void PlayerCameraSystem::Update(std::vector<Entity*> *entities) {
    Entity *playerEntity = GetEntityByComponent<PlayerComponent>(entities);
    if (playerEntity == nullptr) { return; }

    PositionComponent *playerPosition = playerEntity->GetComponent<PositionComponent>();
    CameraComponent *camera = playerEntity->GetComponent<CameraComponent>();
    
    if (playerPosition && camera) {
        camera->camera_.target = (Vector2){ 
            playerPosition->position_.x + 20, 
            playerPosition->position_.y + 20
        };
    }
}

void PlayerCameraSystem::Draw(std::vector<Entity*> *entities) {

}

