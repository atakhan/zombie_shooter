#include "PlayerFeetSystem.h"
#include <iostream>

void PlayerFeetSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerFeetSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    PlayerBodyComponent *playerBody = player->GetComponent<PlayerBodyComponent>();

    if (playerBody) {
        if (leftFoot) {
            DrawCircleV(leftFoot->pos_, leftFoot->radius_, leftFoot->color_);
            DrawCircleV(leftFoot->goalPosition_, 4.0f, leftFoot->color_);
            DrawLineV(leftFoot->pos_, playerBody->pos_, leftFoot->color_);
        }
        if (rightFoot) {
            DrawCircleV(rightFoot->pos_, leftFoot->radius_, rightFoot->color_);
            DrawCircleV(rightFoot->goalPosition_, 4.0f, rightFoot->color_);
            DrawLineV(rightFoot->pos_, playerBody->pos_, rightFoot->color_);
        }
    }
}

void PlayerFeetSystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PlayerComponent *playerComponent = player->GetComponent<PlayerComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();
    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();

    if (!body || !playerHealth || !leftFoot || !rightFoot || !playerDirection || !speed)
    { return; }

    // Move logic
    if (leftFoot && rightFoot) {
        // move feet to the goal by comparing feet pos and goal pos
        if (leftFoot->moving_) {
            if (leftFoot->goalPosition_.x < leftFoot->pos_.x) {
                leftFoot->pos_.x -= 60.0f * GetFrameTime();
            }
            if (leftFoot->goalPosition_.x > leftFoot->pos_.x) {
                leftFoot->pos_.x += 60.0f * GetFrameTime();
            }
        }

        if (rightFoot->moving_) {
            if (rightFoot->goalPosition_.y < rightFoot->pos_.y) {
                rightFoot->pos_.y -= 60.0f * GetFrameTime();
            }
            if (rightFoot->goalPosition_.y > rightFoot->pos_.y) {
                rightFoot->pos_.y += 60.0f * GetFrameTime();
            }
        }
    }
    
}


