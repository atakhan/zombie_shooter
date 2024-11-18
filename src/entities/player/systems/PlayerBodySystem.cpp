#include "PlayerBodySystem.h"
#include <iostream>

void PlayerBodySystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerBodySystem System Initialized" << std::endl;
    player_ = GetEntityByComponent<PlayerComponent>(entities);
    body_ = nullptr;
    if (player_ != nullptr) {
        body_ = player_->GetComponent<PlayerBodyComponent>();
    }
    
}

void PlayerBodySystem::Draw(std::vector<Entity*> *entities) {
    if (body_) {        
        DrawCircleV(body_->pos_, 5.0f, GREEN);
        float leftAngle = body_->rotation_ - body_->limit_;
        float rightAngle = body_->rotation_ + body_->limit_;

        float width = 20.0f * 2;
        float height = 20.0f / 4;
        Rectangle focusRec = {body_->pos_.x, body_->pos_.y, width, height};
        Vector2 focuesRecOrigin = {0.0f, height / 2};
        
        // BODY DIRECTION 
        DrawRectanglePro(focusRec, focuesRecOrigin, body_->rotation_, WHITE); 
        // BODY SHADOW DIRECTION 
        DrawRectanglePro(focusRec, focuesRecOrigin, body_->shadowRotation_, GRAY_6_4);
        
        // LEFT LIMIT EDGE DIRECTION 
        DrawRectanglePro(focusRec, focuesRecOrigin, leftAngle, PINK);
        // RIGHT LIMIT EDGE DIRECTION 
        DrawRectanglePro(focusRec, focuesRecOrigin, rightAngle, PURPLE);
        
        // ANGLE CONVERSION DIRECTION 
        DrawRectanglePro(focusRec, focuesRecOrigin, 180.0f, GREEN);
        // DrawCircleV(body_->goalPosition_, 5.0f, ORANGE);
    }
}

void PlayerBodySystem::Update(std::vector<Entity*> *entities) {
    using namespace std;
    
    PlayerComponent *playerComponent = player_->GetComponent<PlayerComponent>();
    DirectionComponent *playerDirection = player_->GetComponent<DirectionComponent>();

    LeftFootComponent *leftFoot = player_->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player_->GetComponent<RightFootComponent>();

    if (!body_ || !leftFoot || !rightFoot || !playerDirection)
    { return; }

    float xDiff = abs(leftFoot->pos_.x - rightFoot->pos_.x);
    float yDiff = abs(leftFoot->pos_.y - rightFoot->pos_.y);
    body_->pos_ = {
        leftFoot->pos_.x + (xDiff / 2),
        leftFoot->pos_.y + (yDiff / 2)
    };

    float bodyRotation = body_->rotation_;
    float visionRotation = playerDirection->rotation_;

    // if (visionRotation)
    
    // cout << "body rotation in degrees: " << bodyRotation << endl;
    // cout << "vision rotation in radians: " << visionRotation << endl;

    float leftAngle = GetLimitAngle(body_->rotation_ - body_->limit_);
    float rightAngle = GetLimitAngle(body_->rotation_ + body_->limit_);

    if (isPositive(body_->rotation_)) {
        body_->shadowRotation_ = (-180) + body_->rotation_;
    } else {
        body_->shadowRotation_ = (180) + body_->rotation_;
    }

    cout << "range: " << leftAngle << ", "<< rightAngle << endl;
    cout << "antibody : " << body_->shadowRotation_ << endl;
    cout << "vision && body: " << visionRotation << ", " << bodyRotation << endl;
    cout << "right: " << rightAngle << endl;
    cout << "------------" << endl;

    
    if (!isPositive(visionRotation)) {
        cout << "POSITIVE" << endl;
        if (visionRotation > leftAngle) {
            cout << "visionRotation > leftAngle" << endl;
            if (visionRotation > body_->shadowRotation_) {
                RotateToLeft(body_);
            }
        } else {
            cout << "visionRotation <= leftAngle" << endl;
            RotateToLeft(body_);
        }
        
        if (visionRotation > rightAngle) {
            cout << "visionRotation > rightAngle" << endl;
            // cout << "RotateToRight(body_) POSITIVE" << endl;
            RotateToRight(body_);
        } else {
            cout << "visionRotation <= rightAngle" << endl;
            if (visionRotation < body_->shadowRotation_) {
                RotateToRight(body_);
            }
        }
    }
    else {
        cout << "NEGATIVE" << endl;
        // if (visionRotation > leftAngle) {
        //     if (visionRotation > body_->shadowRotation_) {
        //         RotateToLeft(body_);
        //     }
        // } else {
        //     RotateToLeft(body_);
        // }
        
        // if (visionRotation > rightAngle) {
        //     // cout << "RotateToRight(body_) POSITIVE" << endl;
        //     RotateToRight(body_);
        // } else {
        //     if (visionRotation < body_->shadowRotation_) {
        //         RotateToRight(body_);
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
