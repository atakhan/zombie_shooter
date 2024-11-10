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

    if (leftFoot) {        
        DrawCircleV(leftFoot->pos_, leftFoot->radius_, BLUE);
        DrawCircleV(rightFoot->pos_, leftFoot->radius_, VIOLET);
        // DrawCircle(leftFoot->bone_.x, leftFoot->bone_.y, 10.0f, BLUE);
        // DrawRectanglePro(rightFoot->bone_, rightFoot->origin_, rightFoot->rotation_, GREEN);
        // DrawCircleV(leftFoot->goalPosition_, 5.0f, YELLOW);
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


    float collisionRadius = 1.0f;
    float stepValue = 20.0f;
    if (playerComponent->currentState_ == PlayerComponent::WALK) {
        cout << "player state WALK " << endl;
        speed->speed_ = speed->speed_ * 0.5f;
        stepValue = 10.0f;
    } else
    if (playerComponent->currentState_ == PlayerComponent::RUN) {
        cout << "player state RUN " << endl;
        speed->speed_ = speed->speed_ * 2.0f;
        stepValue = 20.0f;
    }
    
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        if (!leftFoot->moving_ && !rightFoot->moving_) {
            leftFoot->moving_ = true;
        }
        
        if (leftFoot->moving_) {
            if (CheckCollisionCircles(
                leftFoot->pos_, collisionRadius, 
                leftFoot->goalPosition_, collisionRadius
            )) {
                leftFoot->idlePos_ = leftFoot->goalPosition_;
                leftFoot->goalPosition_ = Tools::MovePosToRight(leftFoot->goalPosition_, stepValue);
                leftFoot->moving_ = false;
                rightFoot->moving_ = true;
            } else {
                leftFoot->pos_.x += 60.0f * GetFrameTime();
            }
        }

        if (rightFoot->moving_) {
            if (CheckCollisionCircles(
                rightFoot->pos_, collisionRadius, 
                rightFoot->goalPosition_, collisionRadius
            )) {
                rightFoot->idlePos_ = rightFoot->goalPosition_;
                rightFoot->goalPosition_ = Tools::MovePosToRight(rightFoot->goalPosition_, stepValue);
                leftFoot->moving_ = true;
                rightFoot->moving_ = false;
            } else {
                rightFoot->pos_.x += 60.0f * GetFrameTime();
            }
        }

    } else
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
        cout << "key left pressed" << endl;
    } else
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
        cout << "key up pressed" << endl;
    } else
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
        cout << "key down pressed" << endl;
    } else {
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
}

void PlayerStepSystem::Idle(LeftFootComponent* leftFoot, RightFootComponent* rightFoot, PlayerComponent* player) {
    leftFoot->pos_ = leftFoot->idlePos_;
    rightFoot->pos_ = rightFoot->idlePos_;
    player->currentState_ = PlayerComponent::IDLE;
    // leftFoot->moving_ = false;
}

void PlayerStepSystem::MoveRight(PositionComponent *playerPosition, LeftFootComponent *leftFoot, RightFootComponent *rightFoot) {
    Move(leftFoot, playerPosition);
    float stepSize = 10.0f;
    if (CheckCollisionPointCircle(leftFoot->goalPosition_, leftFoot->pos_, leftFoot->radius_)) {
        leftFoot->goalPosition_ = {
            leftFoot->goalPosition_.x + stepSize,
            leftFoot->goalPosition_.y
        };
    }
}

void PlayerStepSystem::MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.x = position->position_.x - speed->speed_;
}

void PlayerStepSystem::MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y - speed->speed_;
}

void PlayerStepSystem::MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y + speed->speed_;
}

void PlayerStepSystem::Move(LeftFootComponent *leftFoot, PositionComponent *playerPosition) {
    float moveVelocity = 1.0f;
    if (leftFoot->pos_.x < leftFoot->goalPosition_.x) {
        leftFoot->pos_.x = leftFoot->pos_.x + moveVelocity;
        // playerPosition->position_.x = playerPosition->position_.x + (moveVelocity/2);
    }
    if (leftFoot->pos_.x > leftFoot->goalPosition_.x) {
        leftFoot->pos_.x = leftFoot->pos_.x - moveVelocity;
        // playerPosition->position_.x = playerPosition->position_.x - (moveVelocity/2);
    }
    if (leftFoot->pos_.y < leftFoot->goalPosition_.y) {
        leftFoot->pos_.y = leftFoot->pos_.y + moveVelocity;
        // playerPosition->position_.y = playerPosition->position_.y + (moveVelocity/2);
    }
    if (leftFoot->pos_.y > leftFoot->goalPosition_.y) {
        leftFoot->pos_.y = leftFoot->pos_.y - moveVelocity;
        // playerPosition->position_.y = playerPosition->position_.y - (moveVelocity/2);
    }
}