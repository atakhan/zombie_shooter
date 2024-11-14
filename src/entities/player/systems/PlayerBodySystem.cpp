#include "PlayerBodySystem.h"
#include <iostream>

void PlayerBodySystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerBodySystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    BodyComponent *playerBody = player->GetComponent<BodyComponent>();

    if (playerBody) {        
        DrawCircleV(playerBody->pos_, 5.0f, GREEN);
        DrawCircleV(playerBody->goalPosition_, 2.0f, ORANGE);
    }
}

void PlayerBodySystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PlayerComponent *playerComponent = player->GetComponent<PlayerComponent>();

    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();

    if (!playerPosition || !playerHealth || !leftFoot || !rightFoot || !playerDirection || !speed)
    { return; }

    float xDiff = abs(leftFoot->pos_.x - rightFoot->pos_.x);
    float yDiff = abs(leftFoot->pos_.y - rightFoot->pos_.y);
    playerPosition->position_ = {
        leftFoot->pos_.x + (xDiff / 2),
        leftFoot->pos_.y + (yDiff / 2)
    };
}

void PlayerBodySystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player) {
    leftFoot->pos_ = leftFoot->idlePos_;
    rightFoot->pos_ = rightFoot->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
}
