#include "PlayerBodySystem.h"
#include <iostream>

void PlayerBodySystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerBodySystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    HealthComponent *health = player->GetComponent<HealthComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();

    if (health && body && leftFoot && rightFoot) {        
        DrawCircleV(body->pos_, 5.0f, GREEN);
    }
}

void PlayerBodySystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PlayerComponent *playerComponent = player->GetComponent<PlayerComponent>();

    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();

    if (!body || !playerHealth || !leftFoot || !rightFoot || !playerDirection || !speed)
    { return; }

    body->pos_ = {
        leftFoot->pos_.x + (abs(leftFoot->pos_.x - rightFoot->pos_.x) / 2),
        leftFoot->pos_.y + (abs(leftFoot->pos_.y - rightFoot->pos_.y) / 2)
    };
    
}

void PlayerBodySystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player) {
    leftFoot->pos_ = leftFoot->idlePos_;
    rightFoot->pos_ = rightFoot->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
}
