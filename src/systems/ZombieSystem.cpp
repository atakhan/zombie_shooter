// ZombieSystem.cpp
#include "ZombieSystem.h"
#include <iostream>

void ZombieSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie System Initialized" << std::endl;
}

void ZombieSystem::Update(std::vector<Entity*> *entities) {
    Player* player;
    for (Entity* entity : *entities) {
        if (dynamic_cast<Player*>(entity)) {
            player = static_cast<Player*>(entity);
        }
    }
    for (Entity* entity : *entities) {
        Zombie* zombie = dynamic_cast<Zombie*>(entity);
        if (zombie) {
            PositionComponent* food = nullptr; 
            food = zombie->FindFood(entities);
            if (food) {
                zombie->SetGoal(food->GetX(), food->GetY());
                zombie->AttackState();
                zombie->Move();
                if (zombie->CanAttack(player)) {
                    zombie->Attack();
                    player->TakeDamage(zombie->Attack());
                }
            } else {
                if (zombie->HasGoal() && zombie->GoalReached() == false) {
                    zombie->Move();
                } else {
                    if (GetRandomHalfProbability(99)) {
                        zombie->FindRandomGoal();
                        zombie->WalkingState();
                        zombie->Move();
                    } else {
                        zombie->IdleState();
                    }
                }
            }
        }
    }
}

bool ZombieSystem::GetRandomHalfProbability(int percent) {
    bool tf = true; //flag, whether the first or second condition's happened
    
    int randNum = rand() % (100-0 + 1) + 0;
    if (randNum < percent) {
        tf = false;
    }
    return tf;
}

