#include "PlayerBodySystem.h"
#include <iostream>

void PlayerBodySystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerBodySystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    PlayerBodyComponent *playerBody = player->GetComponent<PlayerBodyComponent>();

    if (playerBody) {        
        DrawCircleV(playerBody->pos_, 5.0f, GREEN);
        float leftAngle = GetLimitAngle(playerBody->rotation_ - playerBody->limit_);
        float rightAngle = GetLimitAngle(playerBody->rotation_ + playerBody->limit_);
        
        float width = 20.0f * 2;
        float height = 20.0f / 4;
        Rectangle focusRec = {playerBody->pos_.x, playerBody->pos_.y, width, height};
        Vector2 focuesRecOrigin = {0.0f, height / 2};
        
        DrawRectanglePro(focusRec, focuesRecOrigin, leftAngle, PINK);
        DrawRectanglePro(focusRec, focuesRecOrigin, rightAngle, PURPLE);
        
        // DrawCircleV(playerBody->goalPosition_, 5.0f, ORANGE);
    }
}

void PlayerBodySystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }

    PlayerComponent *playerComponent = player->GetComponent<PlayerComponent>();
    PlayerBodyComponent *playerBody = player->GetComponent<PlayerBodyComponent>();

    DirectionComponent *playerDirection = player->GetComponent<DirectionComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();

    if (!playerBody || !leftFoot || !rightFoot || !playerDirection)
    { return; }

    float xDiff = abs(leftFoot->pos_.x - rightFoot->pos_.x);
    float yDiff = abs(leftFoot->pos_.y - rightFoot->pos_.y);
    playerBody->pos_ = {
        leftFoot->pos_.x + (xDiff / 2),
        leftFoot->pos_.y + (yDiff / 2)
    };

    float bodyRotation = playerBody->rotation_;
    float visionRotation = playerDirection->rotation_;
    
    if (visionRotation)
    
    cout << "body rotation in degrees: " << bodyRotation << endl;
    cout << "vision rotation in radians: " << visionRotation << endl;

    // if (playerBody->rotation_ > 180)
    // playerBody->rotation_ += 0.3f;
    float leftAngle = GetLimitAngle(playerBody->rotation_ - playerBody->limit_);
    float rightAngle = GetLimitAngle(playerBody->rotation_ + playerBody->limit_);
    

    cout << "left angle: " << leftAngle << endl;
    cout << "right angle: " << rightAngle << endl;
}

float PlayerBodySystem::GetLimitAngle(float angle) {
    if (angle > 180.0f) {
        float izlishek = angle - 180.0f;
        angle = (180.0f - izlishek) * (-1.0f);
    }
    if (angle < -180.0f) {
        angle = abs(angle - 180.0f);
    }

    return angle;
}
void PlayerBodySystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player) {
    leftFoot->pos_ = leftFoot->idlePos_;
    rightFoot->pos_ = rightFoot->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
}
