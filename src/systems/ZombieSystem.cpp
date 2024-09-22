// ZombieSystem.cpp
#include "ZombieSystem.h"
#include <iostream>

void ZombieSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie System Initialized" << std::endl;
}

void ZombieSystem::Update(std::vector<Entity*> *entities) {
    for (Entity* entity : *entities) {
        Zombie* zombie = dynamic_cast<Zombie*>(entity);
        if (zombie) {
            PositionComponent* eat = nullptr; 
            eat = zombie->FindEat(entities);
            if (eat) {
                zombie->SetGoal(eat->GetPositionX(), eat->GetPositionY());
                zombie->Move();
            } else {
                if (zombie->HasGoal() && zombie->GoalReached() == false) {
                    zombie->Move();
                } else {
                    if (GetRandomHalfProbability(99)) {
                        zombie->FindGoal();
                        zombie->Move();
                    } else {
                        zombie->Idle();
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

