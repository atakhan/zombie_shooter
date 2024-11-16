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
        float leftAngle = playerBody->rotation_ - playerBody->limit_;
        float rightAngle = playerBody->rotation_ + playerBody->limit_;
        
        float width = 20.0f * 2;
        float height = 20.0f / 4;
        Rectangle focusRec = {playerBody->pos_.x, playerBody->pos_.y, width, height};
        Vector2 focuesRecOrigin = {0.0f, height / 2};
        
        DrawRectanglePro(focusRec, focuesRecOrigin, leftAngle, PINK);
        DrawRectanglePro(focusRec, focuesRecOrigin, rightAngle, PURPLE);
        DrawRectanglePro(focusRec, focuesRecOrigin, 180.0f, GREEN);
        DrawRectanglePro(focusRec, focuesRecOrigin, playerBody->rotation_, WHITE);
        DrawRectanglePro(focusRec, focuesRecOrigin, playerBody->shadowRotation_, GRAY_6_4);
        
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

    // if (visionRotation)
    
    // cout << "body rotation in degrees: " << bodyRotation << endl;
    // cout << "vision rotation in radians: " << visionRotation << endl;

    float leftAngle = GetLimitAngle(playerBody->rotation_ - playerBody->limit_);
    float rightAngle = GetLimitAngle(playerBody->rotation_ + playerBody->limit_);

    if (isPositive(playerBody->rotation_)) {
        playerBody->shadowRotation_ = (-180) + playerBody->rotation_;
    } else {
        playerBody->shadowRotation_ = (180) + playerBody->rotation_;
    }

    cout << "range: " << leftAngle << ", "<< rightAngle << endl;
    cout << "antibody : " << playerBody->shadowRotation_ << endl;
    cout << "vision && body: " << visionRotation << ", " << bodyRotation << endl;
    cout << "right: " << rightAngle << endl;
    cout << "------------" << endl;

    
    if (!isPositive(visionRotation)) {
        cout << "POSITIVE" << endl;
        if (visionRotation > leftAngle) {
            cout << "visionRotation > leftAngle" << endl;
            if (visionRotation > playerBody->shadowRotation_) {
                RotateToLeft(playerBody);
            }
        } else {
            cout << "visionRotation <= leftAngle" << endl;
            RotateToLeft(playerBody);
        }
        
        if (visionRotation > rightAngle) {
            cout << "visionRotation > rightAngle" << endl;
            // cout << "RotateToRight(playerBody) POSITIVE" << endl;
            RotateToRight(playerBody);
        } else {
            cout << "visionRotation <= rightAngle" << endl;
            if (visionRotation < playerBody->shadowRotation_) {
                RotateToRight(playerBody);
            }
        }
    }
    else {
        cout << "NEGATIVE" << endl;
        // if (visionRotation > leftAngle) {
        //     if (visionRotation > playerBody->shadowRotation_) {
        //         RotateToLeft(playerBody);
        //     }
        // } else {
        //     RotateToLeft(playerBody);
        // }
        
        // if (visionRotation > rightAngle) {
        //     // cout << "RotateToRight(playerBody) POSITIVE" << endl;
        //     RotateToRight(playerBody);
        // } else {
        //     if (visionRotation < playerBody->shadowRotation_) {
        //         RotateToRight(playerBody);
        //     }
        // }
    }
}

void PlayerBodySystem::RotateToRight(PlayerBodyComponent *playerBody) {
    playerBody->rotation_ += 0.8f;
    if (playerBody->rotation_ > 180.0f) {
        playerBody->rotation_ = -179.0f;
    }
}


void PlayerBodySystem::RotateToLeft(PlayerBodyComponent *playerBody) {
    playerBody->rotation_ -= 0.8f;
    if (playerBody->rotation_ < -180.0f) {
        playerBody->rotation_ = -179.0f;
    }
}

bool PlayerBodySystem::isPositive(float value) {
    return value > 0.0f;
}

float PlayerBodySystem::GetLimitAngle(float angle) {
    if (angle > 180.0f) {
        float izlishek = angle - 180.0f;
        angle = (180.0f - izlishek) * (-1.0f);
        return GetLimitAngle(angle);
    }
    if (angle < -180.0f) {
        angle = abs(angle - 180.0f);
        return GetLimitAngle(angle);
    }

    return angle;
}
void PlayerBodySystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player) {
    leftFoot->pos_ = leftFoot->idlePos_;
    rightFoot->pos_ = rightFoot->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
}
