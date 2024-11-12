#include "PlayerFeetToBodyRelativeSystem.h"
#include <iostream>

void PlayerFeetToBodyRelativeSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;

    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();
    
    if (!body || !leftFoot  || !playerDirection) 
    { return; }

    leftFoot->idlePos_ = (Vector2){body->pos_.x - 20.0f, body->pos_.y};
    rightFoot->idlePos_ = (Vector2){body->pos_.x + 20.0f, body->pos_.y};
}

void PlayerFeetToBodyRelativeSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();

    // Vector2 start = playerPosition->position_;
    // Vector2 leftEnd = leftFoot->pos_;
    // Vector2 rightEnd = rightFoot->pos_;
    DrawCircleV(leftFoot->idlePos_, leftFoot->radius_, leftFoot->color_);
    DrawCircleV(rightFoot->idlePos_, rightFoot->radius_, rightFoot->color_);
    // DrawLineV(start, rightEnd, GREEN);
}

void PlayerFeetToBodyRelativeSystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();
    
    if (!body || !leftFoot || !rightFoot || !playerDirection)
    { return; }

    // TODO: выставлять idle pos в зависимости от направления
    if (!leftFoot->moving_ && !rightFoot->moving_) {
        leftFoot->idlePos_ = (Vector2){body->pos_.x - 20.0f, body->pos_.y};
        rightFoot->idlePos_ = (Vector2){body->pos_.x + 20.0f, body->pos_.y};
    }
}
