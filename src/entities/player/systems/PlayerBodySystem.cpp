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
        direction_ = player_->GetComponent<DirectionComponent>();
        leftAngle_ = body_->rotation_ - body_->limit_;
        rightAngle_ = body_->rotation_ + body_->limit_;
    }
}

void PlayerBodySystem::Draw(std::vector<Entity*> *entities) {
    if (body_) {        
        // DRAW BODY
        DrawCircleV(body_->pos_, 5.0f, GREEN);

        float width = 40.0f;
        float height = 5.0f;
        Rectangle focusRec = {body_->pos_.x, body_->pos_.y, width, height};
        Vector2 focuesRecOrigin = {0.0f, height / 2};
        
        float width2 = 80.0f;
        float height2 = 2.5f;
        Rectangle focusRec2 = {body_->pos_.x, body_->pos_.y, width2, height2};
        Vector2 focuesRecOrigin2 = {0.0f, height2 / 2};

        // BODY DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, body_->rotation_, WHITE);
        // BODY SHADOW DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, body_->shadowRotation_, GRAY_6_4);
        // LEFT LIMIT EDGE DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, leftAngle_, PINK);
        // RIGHT LIMIT EDGE DIRECTION
        DrawRectanglePro(focusRec, focuesRecOrigin, rightAngle_, PURPLE);
        // ANGLE CONVERSION DIRECTION
        DrawRectanglePro(focusRec2, focuesRecOrigin2, 180.0f, GREEN);
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
    leftAngle_ = GetLimitAngle(body_->rotation_ - body_->limit_);
    rightAngle_ = GetLimitAngle(body_->rotation_ + body_->limit_);
}

void PlayerBodySystem::SetShadowRotation() {
    if (isPositive(body_->rotation_)) {
        body_->shadowRotation_ = (-180) + body_->rotation_;
    } else {
        body_->shadowRotation_ = (180) + body_->rotation_;
    }
}

void PlayerBodySystem::RotateBody() {
    float vis = direction_->rotation_;
    float shadow = body_->shadowRotation_;
    float body = body_->rotation_;

    if (isNegative(rightAngle_)) {
        if (isNegative(vis)) {
            if (vis > rightAngle_) {
                std::cout << "move right (-v>-r), ";
            }
        } else {
            if (vis < shadow) {
                std::cout << "move right (+v<+s), ";
            }
        }
    } else {
        if (isNegative(vis)) {
            if (vis < shadow) {
                std::cout << "move right (-v<+s), ";
            }
        } else {
            if (vis > rightAngle_) {
                std::cout << "move right (+v>+r), ";
            }
        }
    }

    // std::cout << "body: " << body;
    // std::cout << ", shad: " << shadow;
    // std::cout << ", left: " << leftAngle_;
    // std::cout << ", right: " << rightAngle_;
    // std::cout << ", vis: " << vis;
    
    // if (vis < rightAngle_) {
    //     std::cout << "move right, ";
    // }
    // if (vis > leftAngle_) {
    //     std::cout << "vis > left, ";
    // } else {
    //     std::cout << "vis < left, ";
    // }
    
    // if (vis > rightAngle_) {
    //     std::cout << "vis > right, ";
    // } else {
    //     std::cout << "vis < right, ";
    // }

    // if (vis > shadow) {
    //     std::cout << "vis > shadow, ";
    // } else {
    //     std::cout << "vis < shadow, ";
    // }
    
    // if (vis < 0.0f) {
    //     std::cout << "vis neg, ";
    // } else {
    //     std::cout << "vis pos, ";
    // }

    // std::cout << "vis: " << vis;
    // std::cout << ", right: " << rightAngle_ << ", ";
    // std::cout << ", left: " << leftAngle_ << ", ";

    // std::cout << "left: " << leftAngle_ << ", right: " << rightAngle_ << ", ";
    // std::cout << "vis - body " << vis - body_->rotation_;
    // std::cout << "outside view, ";
    // std::cout << "inside view, ";

    std::cout << std::endl;
}

void PlayerBodySystem::RotateToRight() {
    body_->rotation_ += 0.8f;
    if (body_->rotation_ > 180.0f) {
        body_->rotation_ = -179.0f;
    }
}

void PlayerBodySystem::RotateToLeft() {
    std::cout << "RotateToLeft" << std::endl;
    body_->rotation_ -= 0.8f;
    if (body_->rotation_ < -179.0f) {
        body_->rotation_ = 179.0f;
    }
}

bool PlayerBodySystem::isPositive(float value) {
    return value >= 0.0f;
}

bool PlayerBodySystem::isNegative(float value) {
    return value < 0.0f;
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
