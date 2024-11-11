#include "PlayerStepSystem.h"
#include <iostream>

void PlayerStepSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerStepSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    HealthComponent *health = player->GetComponent<HealthComponent>();
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();

    if (leftFoot && rightFoot) {
        DrawCircleV(leftFoot->pos_, leftFoot->radius_, BLUE);
        DrawCircleV(rightFoot->pos_, leftFoot->radius_, VIOLET);
        DrawCircleV(leftFoot->goalPosition_, 4.0f, BLUE);
        DrawCircleV(rightFoot->goalPosition_, 4.0f, VIOLET);
    }
}

void PlayerStepSystem::Update(std::vector<Entity*> *entities) {
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

    float collisionRadius = 10.0f;
    float stepValue = 40.0f;
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.x < rightFoot->pos_.x));
        MoveFeetRight(leftFoot, rightFoot, collisionRadius, stepValue);
    } else
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.x < rightFoot->pos_.x));
        MoveFeetLeft(leftFoot, rightFoot, collisionRadius, stepValue);
    } else
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.y < rightFoot->pos_.y));
        MoveFeetUp(leftFoot, rightFoot, collisionRadius, stepValue);
    } else
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.y < rightFoot->pos_.y));
        MoveFeetDown(leftFoot, rightFoot, collisionRadius, stepValue);
    } else {
        Idle(leftFoot, rightFoot, playerComponent, collisionRadius);
    }
}

void PlayerStepSystem::WhoIsFirst(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool leftFirst) {
    if (!leftFoot->moving_ && !rightFoot->moving_) {
        if (leftFirst) {
            leftFoot->moving_ = true;
        } else {
            rightFoot->moving_ = true;
        }
    }
}

void PlayerStepSystem::MoveLeftFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, Vector2 newGoalPos, float collisionRadius) {
    // Move Right
    if (leftFoot->moving_) {
        if (leftFoot->pos_.x > leftFoot->goalPosition_.x) {
            leftFoot->goalPosition_ = newGoalPos;
            leftFoot->idlePos_ = leftFoot->goalPosition_;
            leftFoot->moving_ = false;
            rightFoot->moving_ = true;
        } else {
            leftFoot->pos_.x = leftFoot->pos_.x + (60.0f * GetFrameTime());
            rightFoot->moving_ = false;
        }
    }

    // Move Left
    if (leftFoot->moving_) {
        if (leftFoot->pos_.x > leftFoot->goalPosition_.x) {
            leftFoot->pos_.x = leftFoot->pos_.x - (60.0f * GetFrameTime());
            rightFoot->moving_ = false;
        } else {
            leftFoot->goalPosition_.x = leftFoot->idlePos_.x - stepValue;
            leftFoot->idlePos_ = leftFoot->goalPosition_;
            leftFoot->moving_ = false;
            rightFoot->moving_ = true;
        }
    }
}

void PlayerStepSystem::MoveFeetRight(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    MoveLeftFoot(leftFoot, rightFoot, (Vector2){leftFoot->idlePos_.x + stepValue}, collisionRadius);
    if (rightFoot->moving_) {
        if (rightFoot->pos_.x > rightFoot->goalPosition_.x) {
            rightFoot->goalPosition_.x = rightFoot->idlePos_.x + stepValue;
            rightFoot->idlePos_ = rightFoot->goalPosition_;
            leftFoot->moving_ = true;
            rightFoot->moving_ = false;
        } else {
            rightFoot->pos_.x += 60.0f * GetFrameTime();
            leftFoot->moving_ = false;
        }
    }
}

void PlayerStepSystem::MoveFeetLeft(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    
    if (rightFoot->moving_) {
        if (rightFoot->pos_.x > leftFoot->goalPosition_.x) {
            rightFoot->pos_.x -= 60.0f * GetFrameTime();
            leftFoot->moving_ = false;
        } else {
            rightFoot->idlePos_ = rightFoot->goalPosition_;
            rightFoot->goalPosition_.x = rightFoot->goalPosition_.x - stepValue;
            leftFoot->moving_ = true;
            rightFoot->moving_ = false;
        }
    }
}

void PlayerStepSystem::MoveFeetUp(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    if (leftFoot->moving_) {
        if (CheckCollisionCircles(leftFoot->pos_, collisionRadius, leftFoot->goalPosition_, collisionRadius)){
            leftFoot->idlePos_ = leftFoot->goalPosition_;
            leftFoot->goalPosition_.y = leftFoot->goalPosition_.y - stepValue;
            leftFoot->moving_ = false;
            rightFoot->moving_ = true;
        } else {
            leftFoot->pos_.y -= 60.0f * GetFrameTime();
        }
    }
    if (rightFoot->moving_) {
        if (CheckCollisionCircles(rightFoot->pos_, collisionRadius, rightFoot->goalPosition_, collisionRadius)) {
            rightFoot->idlePos_ = rightFoot->goalPosition_;
            rightFoot->goalPosition_.y = rightFoot->goalPosition_.y - stepValue;
            leftFoot->moving_ = true;
            rightFoot->moving_ = false;
        } else {
            rightFoot->pos_.y -= 60.0f * GetFrameTime();
        }
    }
}

void PlayerStepSystem::MoveFeetDown(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, float collisionRadius, float stepValue) {
    if (leftFoot->moving_) {
        if (CheckCollisionCircles(leftFoot->pos_, collisionRadius, leftFoot->goalPosition_, collisionRadius)){
            leftFoot->idlePos_ = leftFoot->goalPosition_;
            leftFoot->goalPosition_.y = leftFoot->goalPosition_.y + stepValue;
            leftFoot->moving_ = false;
            rightFoot->moving_ = true;
        } else {
            leftFoot->pos_.y += 60.0f * GetFrameTime();
        }
    }
    if (rightFoot->moving_) {
        if (CheckCollisionCircles(rightFoot->pos_, collisionRadius, rightFoot->goalPosition_, collisionRadius)) {
            rightFoot->idlePos_ = rightFoot->goalPosition_;
            rightFoot->goalPosition_.y = rightFoot->goalPosition_.y + stepValue;
            leftFoot->moving_ = true;
            rightFoot->moving_ = false;
        } else {
            rightFoot->pos_.y += 60.0f * GetFrameTime();
        }
    }
}

void PlayerStepSystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player, float collisionRadius) {
    leftFoot->pos_ = leftFoot->idlePos_;
    rightFoot->pos_ = rightFoot->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
    if (leftFoot->moving_) {
            if (!CheckCollisionCircles(leftFoot->pos_, collisionRadius, leftFoot->goalPosition_, collisionRadius)) {
                if (!CheckCollisionCircles(leftFoot->pos_, collisionRadius, leftFoot->idlePos_, collisionRadius)) {
                    leftFoot->pos_.x -= 60.0f * GetFrameTime();
                } else {
                    leftFoot->moving_ = false;
                    leftFoot->pos_ = leftFoot->idlePos_;
                }
            }
        }
        if (rightFoot->moving_) {
            if (!CheckCollisionCircles(rightFoot->pos_, collisionRadius, rightFoot->goalPosition_, collisionRadius)) {
                if (!CheckCollisionCircles(rightFoot->pos_, collisionRadius, rightFoot->idlePos_, collisionRadius)) {
                    rightFoot->pos_.x -= 60.0f * GetFrameTime();
                } else {
                    rightFoot->moving_ = false;
                    rightFoot->pos_ = rightFoot->idlePos_;
                }
            }
        }
}
