#include "PlayerMoveSystem.h"
#include <iostream>

void PlayerMoveSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerFeetMove System Initialized" << std::endl;
}

void PlayerMoveSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    HealthComponent *health = player->GetComponent<HealthComponent>();
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();

    if (leftFoot) {        
        DrawRectanglePro(leftFoot->bone_, leftFoot->origin_, leftFoot->rotation_, BLUE);
        // DrawRectanglePro(rightFoot->bone_, rightFoot->origin_, rightFoot->rotation_, GREEN);
        // DrawCircleV(leftFoot->goalPosition_, 5.0f, YELLOW);
    }
    if (playerPosition && health) {
        DrawCircleV(playerPosition->position_, health->health_/10, RED);
    }
}

void PlayerMoveSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    DirectionComponent *direction = player->GetComponent<DirectionComponent>();
    PositionComponent *playerPosition = player->GetComponent<PositionComponent>();
    HealthComponent *playerHealth = player->GetComponent<HealthComponent>();
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();
    RightFootComponent *rightFoot = player->GetComponent<RightFootComponent>();
    SpeedComponent *speed = player->GetComponent<SpeedComponent>();

    if (!playerPosition || !playerHealth || !leftFoot || !rightFoot || !direction || !speed) { return; }
    Move(leftFoot, playerPosition);
    // leftFoot->origin_;
    // leftFoot->rotation_;
    // leftFoot->moving_;
    


    // SetDefaultPosition(feet, playerHealth, playerPosition);
    // if (leftFoot->moving_ == false) {
    // }

    // if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //     leftFoot->goalPosition_ = {
    //         leftFoot->goalPosition_.x + moveVelocity, 
    //         leftFoot->goalPosition_.y
    //     };
    //     leftFoot->moving_ = true;
    // }

    // if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_D)) {
    //     leftFoot->moving_ = false;
    // }

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            Idle(leftFoot, playerPosition);
        } else {
            if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
                MoveRight(playerPosition, leftFoot, rightFoot);
                // MoveTop(playerPosition, leftFoot, rightFoot);
            } else
            if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
                MoveRight(playerPosition, leftFoot, rightFoot);
                // MoveBottom(playerPosition, leftFoot, rightFoot);
            } else {
                MoveRight(playerPosition, leftFoot, rightFoot);
            }
        }
    // } else
    // if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    //     if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //         Idle(leftFoot, playerPosition);
    //     } else {
    //         if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W) ) {
    //             MoveLeft(playerPosition, leftFoot, rightFoot);
    //             MoveTop(playerPosition, leftFoot, rightFoot);
    //         } else
    //         if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    //             MoveLeft(playerPosition, leftFoot, rightFoot);
    //             MoveBottom(playerPosition, leftFoot, rightFoot);
    //         } else {
    //             MoveLeft(playerPosition, leftFoot, rightFoot);
    //         }
    //     }
    // } else
    // if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    //     if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    //         Idle(leftFoot, playerPosition);
    //     } else {
    //         if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //             MoveTop(playerPosition, leftFoot, rightFoot);
    //             MoveRight(playerPosition, leftFoot, rightFoot);
    //         } else
    //         if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    //             MoveTop(playerPosition, leftFoot, rightFoot);
    //             MoveLeft(playerPosition, leftFoot, rightFoot);
    //         } else {
    //             MoveTop(playerPosition, leftFoot, rightFoot);
    //         }
    //     }
    // } else
    // if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    //     if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    //         Idle(leftFoot, playerPosition);
    //     } else {
    //         if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    //             MoveBottom(playerPosition, leftFoot, rightFoot);
    //             MoveRight(playerPosition, leftFoot, rightFoot);
    //         } else
    //         if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    //             MoveBottom(playerPosition, leftFoot, rightFoot);
    //             MoveLeft(playerPosition, leftFoot, rightFoot);
    //         } else {
    //             MoveBottom(playerPosition, leftFoot, rightFoot);
    //         }
    //     }
    } else {
        Idle(leftFoot, playerPosition);
    }
}

void PlayerMoveSystem::Idle(LeftFootComponent* leftFoot, PositionComponent *playerPosition) {
    leftFoot->bone_.x = playerPosition->position_.x;
    leftFoot->bone_.y = playerPosition->position_.y;
    leftFoot->goalPosition_ = {
        playerPosition->position_.x, 
        playerPosition->position_.y, 
    };
    // leftFoot->moving_ = false;
}

void PlayerMoveSystem::SetDefaultPosition(FeetComponent* feet, HealthComponent *playerHealth, PositionComponent *playerPosition) {
    float coef = 2.0f;
    feet->left_.width = playerHealth->health_ * coef;
    feet->left_.height = (playerHealth->health_ / 2.0f) * coef;
    
    float footVelocity = 3.0f;
    if (feet->left_.x < playerPosition->position_.x) {
        feet->left_.x = feet->left_.x + footVelocity;
    }
    if (feet->left_.x > playerPosition->position_.x) {
        feet->left_.x = feet->left_.x - footVelocity;
    }
    if (feet->left_.y < playerPosition->position_.y) {
        feet->left_.y = feet->left_.y + footVelocity;
    }
    if (feet->left_.y > playerPosition->position_.y) {
        feet->left_.y = feet->left_.y - footVelocity;
    }
    
    feet->right_.width = (playerHealth->health_) * coef;
    feet->right_.height = (playerHealth->health_ / 2.0f) * coef; 
    feet->right_.x = playerPosition->position_.x;
    feet->right_.y = playerPosition->position_.y;
}

void PlayerMoveSystem::SetRotationCenter(FeetComponent* feet) {
    // Определяем координаты углов
    Vector2 corners[4];
    // Верхний левый угол
    corners[0] = { 0.0f, 0.0f };
    // Верхний правый угол
    corners[1] = { 0.0f + feet->left_.width, 0.0f }; 
    // Нижний правый угол
    corners[2] = { 0.0f + feet->left_.width, 0.0f + feet->left_.height }; 
    // Нижний левый угол
    corners[3] = { 0.0f, 0.0f + feet->left_.height }; 

    // Вычисляем новый центр вращения (например, центр прямоугольника)
    Vector2 rotationOrigin_center = { (corners[0].x + corners[2].x) / 2, (corners[0].y + corners[2].y) / 2 };
    Vector2 rotationOrigin_topLeft = corners[0];
    Vector2 rotationOrigin_topRight = corners[1];
    Vector2 rotationOrigin_bottomRight = corners[2];
    Vector2 rotationOrigin_bottomLeft = corners[3];
    Vector2 rotationOrigin_bottomCenter = { (corners[0].x + corners[2].x) / 2, corners[0].y};
    Vector2 rotationOrigin_topCenter = { (corners[0].x + corners[2].x) / 2, (corners[0].y + corners[2].y) };
    
    feet->leftOrigin_ = rotationOrigin_bottomCenter;
    feet->rightOrigin_ = rotationOrigin_topCenter;
}

void PlayerMoveSystem::MoveRight(PositionComponent *playerPosition, LeftFootComponent *leftFoot, RightFootComponent *rightFoot) {
    Move(leftFoot, playerPosition);
    float stepSize = 10.0f;
    if (CheckCollisionPointRec(leftFoot->goalPosition_, leftFoot->bone_)) {
        leftFoot->goalPosition_ = {
            leftFoot->goalPosition_.x + stepSize,
            leftFoot->goalPosition_.y
        };
    }
}

void PlayerMoveSystem::MoveLeft(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.x = position->position_.x - speed->speed_;
}

void PlayerMoveSystem::MoveTop(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y - speed->speed_;
}

void PlayerMoveSystem::MoveBottom(SoundComponent *sound, PositionComponent *position, SpeedComponent *speed) {
    position->position_.y = position->position_.y + speed->speed_;
}

void PlayerMoveSystem::Move(LeftFootComponent *leftFoot, PositionComponent *playerPosition) {
    float moveVelocity = 1.0f;
    if (leftFoot->bone_.x < leftFoot->goalPosition_.x) {
        leftFoot->bone_.x = leftFoot->bone_.x + moveVelocity;
        // playerPosition->position_.x = playerPosition->position_.x + (moveVelocity/2);
    }
    if (leftFoot->bone_.x > leftFoot->goalPosition_.x) {
        leftFoot->bone_.x = leftFoot->bone_.x - moveVelocity;
        // playerPosition->position_.x = playerPosition->position_.x - (moveVelocity/2);
    }
    if (leftFoot->bone_.y < leftFoot->goalPosition_.y) {
        leftFoot->bone_.y = leftFoot->bone_.y + moveVelocity;
        // playerPosition->position_.y = playerPosition->position_.y + (moveVelocity/2);
    }
    if (leftFoot->bone_.y > leftFoot->goalPosition_.y) {
        leftFoot->bone_.y = leftFoot->bone_.y - moveVelocity;
        // playerPosition->position_.y = playerPosition->position_.y - (moveVelocity/2);
    }
}