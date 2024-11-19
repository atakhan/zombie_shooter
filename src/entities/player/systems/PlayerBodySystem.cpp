#include "PlayerBodySystem.h"
#include <iostream>

void PlayerBodySystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerBodySystem System Initialized" << std::endl;
    player_ = GetEntityByComponent<PlayerComponent>(entities);
    body_ = nullptr;
    leftFoot_ = nullptr;
    rightFoot_ = nullptr;

    if (player_ != nullptr) {
        body_ = player_->GetComponent<PlayerBodyComponent>();
        leftFoot_ = player_->GetComponent<LeftFootComponent>();
        rightFoot_ = player_->GetComponent<RightFootComponent>();
        leftAngle_ = body_->rotation_ - body_->limit_;
        rightAngle_ = body_->rotation_ + body_->limit_;
    }
}

void PlayerBodySystem::Draw(std::vector<Entity*> *entities) {
    if (body_) {        
        // DRAW BODY
        DrawCircleV(body_->pos_, 5.0f, GREEN);

        float width = 20.0f * 2;
        float height = 20.0f / 4;
        Rectangle focusRec = {body_->pos_.x, body_->pos_.y, width, height};
        Vector2 focuesRecOrigin = {0.0f, height / 2};

        // BODY DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, body_->rotation_, WHITE);
        // BODY SHADOW DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, body_->shadowRotation_, GRAY_6_4);
        // LEFT LIMIT EDGE DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, leftAngle_, PINK);
        // RIGHT LIMIT EDGE DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, rightAngle_, PURPLE);
        // ANGLE CONVERSION DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, 180.0f, GREEN);
        // DrawCircleV(body_->goalPosition_, 5.0f, ORANGE);
    }
}

void PlayerBodySystem::Update(std::vector<Entity*> *entities) {
    if (body_ && leftFoot_ && rightFoot_ && direction_) {
        LocateBody();
        SetLeftRightLimits();
        SetShadowRotation();
        RotateBody();
    }
}

void PlayerBodySystem::LocateBody() {
    float xDiff = abs(leftFoot_->pos_.x - rightFoot_->pos_.x);
    float yDiff = abs(leftFoot_->pos_.y - rightFoot_->pos_.y);
    body_->pos_ = {
        leftFoot_->pos_.x + (xDiff / 2),
        leftFoot_->pos_.y + (yDiff / 2)
    };
}

void PlayerBodySystem::SetLeftRightLimits() {
    leftAngle_ = body_->rotation_ - body_->limit_;
    rightAngle_ = body_->rotation_ + body_->limit_;
}

void PlayerBodySystem::SetShadowRotation() {
    if (isPositive(body_->rotation_)) {
        body_->shadowRotation_ = (-180) + body_->rotation_;
    } else {
        body_->shadowRotation_ = (180) + body_->rotation_;
    }
}

// TODO bugs bugs...
void PlayerBodySystem::RotateBody() {
    if (!isPositive(direction_->rotation_)) {
        if (direction_->rotation_ > leftAngle_) {
            if (direction_->rotation_ > body_->shadowRotation_) {
                RotateToLeft();
            }
        } else {
            RotateToLeft();
        }

        // if (direction_->rotation_ > rightAngle_) {
        //     RotateToRight();
        // } else {
        //     if (direction_->rotation_ < body_->shadowRotation_) {
        //         RotateToRight();
        //     }
        // }
    }
    else {
    }
}

void PlayerBodySystem::RotateToRight() {
    body_->rotation_ += 0.8f;
    if (body_->rotation_ > 180.0f) {
        body_->rotation_ = -179.0f;
    }
}

void PlayerBodySystem::RotateToLeft() {
    body_->rotation_ -= 0.8f;
    if (body_->rotation_ < -180.0f) {
        body_->rotation_ = -179.0f;
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

void PlayerBodySystem::Idle(PlayerComponent* player) {
    leftFoot_->pos_ = leftFoot_->idlePos_;
    rightFoot_->pos_ = rightFoot_->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
}
