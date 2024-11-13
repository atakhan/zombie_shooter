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

    float stepValue = 40.0f;
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        WhoIsFirst(
            leftFoot, rightFoot, 
            (leftFoot->pos_.x < rightFoot->pos_.x)
        );
        MoveLeftFoot(
            leftFoot, rightFoot,
            (bool)(leftFoot->pos_.x > leftFoot->goalPosition_.x),
            (Vector2){playerPosition->position_.x + stepValue, playerPosition->position_.y}
        );
        MoveRightFoot(
            leftFoot, rightFoot, 
            (bool)(rightFoot->pos_.x > rightFoot->goalPosition_.x),
            (Vector2){playerPosition->position_.x + stepValue, playerPosition->position_.y}
        );
    }
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        WhoIsFirst(
            leftFoot, rightFoot, 
            (leftFoot->pos_.x < rightFoot->pos_.x)
        );
        MoveLeftFoot(
            leftFoot, rightFoot, 
            (bool)(leftFoot->pos_.x < leftFoot->goalPosition_.x),
            (Vector2){playerPosition->position_.x - stepValue, playerPosition->position_.y}
        );
        MoveRightFoot(
            leftFoot, rightFoot, 
            (bool)(rightFoot->pos_.x < rightFoot->goalPosition_.x),
            (Vector2){playerPosition->position_.x - stepValue, playerPosition->position_.y}
        );
    }
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        WhoIsFirst(
            leftFoot, rightFoot, 
            (leftFoot->pos_.y < rightFoot->pos_.y)
        );
        MoveLeftFoot(
            leftFoot, rightFoot, 
            (bool)(leftFoot->pos_.y < leftFoot->goalPosition_.y),
            (Vector2){playerPosition->position_.x, playerPosition->position_.y - stepValue}
        );
        MoveRightFoot(
            leftFoot, rightFoot, 
            (bool)(rightFoot->pos_.y < rightFoot->goalPosition_.y),
            (Vector2){playerPosition->position_.x, playerPosition->position_.y - stepValue}
        );
    }
    else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        WhoIsFirst(leftFoot, rightFoot, (leftFoot->pos_.y < rightFoot->pos_.y));
        MoveLeftFoot(
            leftFoot, rightFoot, 
            (bool)(leftFoot->pos_.y > leftFoot->goalPosition_.y),
            (Vector2){playerPosition->position_.x, playerPosition->position_.y + stepValue}
        );
        MoveRightFoot(
            leftFoot, rightFoot, 
            (bool)(rightFoot->pos_.y > rightFoot->goalPosition_.y),
            (Vector2){playerPosition->position_.x, playerPosition->position_.y + stepValue}
        );
    }
    else {
        Idle(leftFoot, rightFoot, playerComponent);
    }

    Move(leftFoot, rightFoot);
}

void PlayerStepSystem::Move(LeftFootComponent *leftFoot, RightFootComponent *rightFoot) {
    if (leftFoot->moving_) {
        if (Tools::CompareFloats(leftFoot->pos_.x, leftFoot->goalPosition_.x, 0.1f) == false) {
            if (leftFoot->pos_.x < leftFoot->goalPosition_.x) {
                leftFoot->pos_.x = (leftFoot->pos_.x + (60.0f * GetFrameTime()));
            } else {
                leftFoot->pos_.x = (leftFoot->pos_.x - (60.0f * GetFrameTime()));
            }

        }
        if (Tools::CompareFloats(leftFoot->pos_.y, leftFoot->goalPosition_.y, 0.1f) == false) {
            if (leftFoot->pos_.y < leftFoot->goalPosition_.y) {
                leftFoot->pos_.y = (leftFoot->pos_.y + (60.0f * GetFrameTime()));
            } else {
                leftFoot->pos_.y = (leftFoot->pos_.y - (60.0f * GetFrameTime()));
            }
        }
    }
    if (rightFoot->moving_) {
        if (Tools::CompareFloats(rightFoot->pos_.x, rightFoot->goalPosition_.x, 0.1f) == false) {
            if (rightFoot->pos_.x < rightFoot->goalPosition_.x) {
                rightFoot->pos_.x = (rightFoot->pos_.x + (60.0f * GetFrameTime()));
            } else {
                rightFoot->pos_.x = (rightFoot->pos_.x - (60.0f * GetFrameTime()));
            }
        }
        if (Tools::CompareFloats(rightFoot->pos_.y, rightFoot->goalPosition_.y, 0.1f) == false) {
            if (rightFoot->pos_.y < rightFoot->goalPosition_.y) {
                rightFoot->pos_.y = (rightFoot->pos_.y + (60.0f * GetFrameTime()));
            } else {
                rightFoot->pos_.y = (rightFoot->pos_.y - (60.0f * GetFrameTime()));
            }
        }
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

void PlayerStepSystem::MoveLeftFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool goalReached, Vector2 newGoalPos) {
    if (leftFoot->moving_) {
        if (goalReached) {
            leftFoot->goalPosition_ = newGoalPos;
            leftFoot->moving_ = false;
            rightFoot->moving_ = true;
        } else {
            rightFoot->moving_ = false;
        }
    }
}

void PlayerStepSystem::MoveRightFoot(LeftFootComponent *leftFoot, RightFootComponent *rightFoot, bool goalReached, Vector2 newGoalPos) {
    if (rightFoot->moving_) {
        if (goalReached) {
            rightFoot->goalPosition_ = newGoalPos;
            leftFoot->moving_ = true;
            rightFoot->moving_ = false;
        } else {
            leftFoot->moving_ = false;
        }
    }
}

void PlayerStepSystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player) {
    player->currentState_ = PlayerComponent::IDLE;
    if (leftFoot->moving_) {
        leftFoot->goalPosition_ = leftFoot->idlePos_;
    }
    if (rightFoot->moving_) {
        rightFoot->goalPosition_ = rightFoot->idlePos_;
    }
}
