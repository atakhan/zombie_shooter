#include "PlayerLeftFootSystem.h"
#include <iostream>

void PlayerLeftFootSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "PlayerLeftFootSystem System Initialized" << std::endl;
}

void PlayerLeftFootSystem::Draw(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    if (player == nullptr) { return; }
    
    LeftFootComponent *leftFoot = player->GetComponent<LeftFootComponent>();

    if (leftFoot) {
        DrawCircleV(leftFoot->pos_, leftFoot->radius_, BLUE);
        // DrawCircleV(leftFoot->goalPosition_, 4.0f, BLUE);
    }
}

void PlayerLeftFootSystem::Update(std::vector<Entity*> *entities) {
    
    using namespace std;
    
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    
    if (player == nullptr) { return; }

    LeftFootComponent *foot = player->GetComponent<LeftFootComponent>();
    PlayerBodyComponent *body = player->GetComponent<PlayerBodyComponent>();

    if (!foot) { return; }

    MoveFromBody(foot, body);
    // if (foot->moving_) {
    //     if (GoalReached(foot)) {
    //         foot->moving_ = false;
    //     } else {
    //         MoveToGoal(foot);
    //     }
    // }

}

bool PlayerLeftFootSystem::GoalReached(LeftFootComponent *foot) {
    if (CheckCollisionPointCircle(foot->goalPosition_, foot->pos_, foot->radius_)) {
        return true;
    }
    return false;
}

void PlayerLeftFootSystem::MoveToGoal(LeftFootComponent *foot) {
    Vector2 newPos = {
        foot->goalPosition_.x,
        foot->goalPosition_.y
    };
    
    foot->pos_ = newPos;
}

void PlayerLeftFootSystem::MoveFromBody(LeftFootComponent *foot, PlayerBodyComponent *body) {
    Vector2 newPos = {
        body->pos_.x - 21.0f,
        body->pos_.y
    };
    
    foot->pos_ = newPos;
}
