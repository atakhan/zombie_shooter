#include "ZombieMoveSystem.h"

void ZombieMoveSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie Draw System Initialized" << std::endl;
}

void ZombieMoveSystem::Draw(std::vector<Entity*> *entities) {}

void ZombieMoveSystem::Update(std::vector<Entity*> *entities) {
    Entity *player;
    for (auto& entity : *entities) {
        if (entity->HasComponent<PlayerComponent>()) {
            player = entity;
            break;
        }
    }
    
    PositionComponent* playerPosition = nullptr;
    if (player->HasComponent<PositionComponent>()) {
        playerPosition = player->GetComponent<PositionComponent>();
    }
    
    SoundComponent* playerSound = nullptr;
    if (player->HasComponent<SoundComponent>()) {
        playerSound = player->GetComponent<SoundComponent>();
    }
    
    HealthComponent* playerHealth = nullptr;
    if (player->HasComponent<HealthComponent>()) {
        playerHealth = player->GetComponent<HealthComponent>();
    }

    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue;
        }
        if (entity->HasComponent<ZombieComponent>()) {
            ZombieComponent* zombieComponent = entity->GetComponent<ZombieComponent>();
            
            PositionComponent* zombiePosition = nullptr;
            HealthComponent* zombieRadius = nullptr;
            TargetComponent* target = nullptr;
            SpeedComponent* speed = nullptr;
            AttackComponent* attack = nullptr;

            if (entity->HasComponent<PositionComponent>()) {
                zombiePosition = entity->GetComponent<PositionComponent>();
            }
            if (entity->HasComponent<HealthComponent>()) {
                zombieRadius = entity->GetComponent<HealthComponent>();
            }
            if (entity->HasComponent<TargetComponent>()) {
                target = entity->GetComponent<TargetComponent>();
            }
            if (entity->HasComponent<SpeedComponent>()) {
                speed = entity->GetComponent<SpeedComponent>();
            }
            if (entity->HasComponent<AttackComponent>()) {
                attack = entity->GetComponent<AttackComponent>();
            }

            if (zombiePosition && zombieRadius && target && playerPosition && playerSound) {
                PositionComponent* food = nullptr; 
                food = FindFood(zombiePosition, playerPosition, zombieRadius->health_, playerSound->currentRadius);
                if (food) {
                    target->position_ = food->position_;
                    zombieComponent->currentState = ZombieComponent::Status::RUN;
                    MoveToTarget(zombiePosition, target, speed->speed_ * Config::RUN_COEF);
                    if (ZombieCanAttack(playerPosition, zombiePosition, playerHealth->health_, attack->radius_)) {
                        if (playerHealth->health_ > 0) {
                            playerHealth->health_ = playerHealth->health_ - attack->attackStrength_;
                        }
                    }
                } else {

                }
            }
        }
    }
}

// void ZombieSystem::Update(std::vector<Entity*> *entities) {
//     Player* player;
//     for (Entity* entity : *entities) {
//         if (dynamic_cast<Player*>(entity)) {
//             player = static_cast<Player*>(entity);
//         }
//     }
//     for (Entity* entity : *entities) {
//         Zombie* zombie = dynamic_cast<Zombie*>(entity);
//         if (zombie) {
//             PositionComponent* food = nullptr; 
//             food = zombie->FindFood(entities);
//             if (food) {
//                 zombie->SetGoal(food->GetX(), food->GetY());
//                 zombie->AttackState();
//                 zombie->Move();
//                 if (zombie->CanAttack(player)) {
//                     zombie->Attack();
//                     player->TakeDamage(zombie->Attack());
//                 }
//             } else {
//                 if (zombie->HasGoal() && zombie->GoalReached() == false) {
//                     zombie->Move();
//                 } else {
//                     if (GetRandomHalfProbability(99)) {
//                         zombie->FindRandomGoal();
//                         zombie->WalkingState();
//                         zombie->Move();
//                     } else {
//                         zombie->IdleState();
//                     }
//                 }
//             }
//         }
//     }
// }

bool ZombieMoveSystem::GetRandomHalfProbability(int percent) {
    bool tf = true; //flag, whether the first or second condition's happened
    
    int randNum = rand() % (100-0 + 1) + 0;
    if (randNum < percent) {
        tf = false;
    }
    return tf;
}

PositionComponent *ZombieMoveSystem::FindFood(
        PositionComponent *zombiePosition,
        PositionComponent *playerPosition, 
        float zombieRadius, 
        float playerSoundRadius
) {
    PositionComponent *result = nullptr;

    float playerPosX = playerPosition->position_.x;
    float playerPosY = playerPosition->position_.y;

    float zombiePosX = zombiePosition->position_.x;
    float zombiePosY = zombiePosition->position_.y;

    float posXDif = playerPosX - zombiePosX;
    float posYDif = playerPosY - zombiePosY;

    float radius_sum = playerSoundRadius + zombieRadius;
    
    // if zombie hears player, then return player pos
    if (fabs(((posXDif * posXDif) + (posYDif * posYDif))) <= (radius_sum * radius_sum)) {
        result = new PositionComponent(playerPosX, playerPosY);
    }

    return result;
}

void ZombieMoveSystem::MoveToTarget(PositionComponent *position, TargetComponent *target, float speed) {
    float targetX = target->position_.x;
    float targetY = target->position_.y;
    float posX = position->position_.x;
    float posY = position->position_.y;
    float deltaX = targetX - posX;
    float deltaY = targetY - posY;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance > 0) {
        float moveX = (deltaX / distance) * speed;
        float moveY = (deltaY / distance) * speed;

        posX += moveX;
        posY += moveY;

        position->position_.x = posX;
        position->position_.y = posY;

        if (std::abs(deltaX) < speed && std::abs(deltaY) < speed) {
            posX = targetX;
            posY = targetY;
        }
    }
}

bool ZombieMoveSystem::ZombieCanAttack(PositionComponent *playerPos, PositionComponent *zombiePos, float playerRadius, float attackRadius) {
    float playerPosX = playerPos->position_.x;
    float playerPosY = playerPos->position_.y;
    float posXDif = playerPosX - zombiePos->position_.x;
    float posYDif = playerPosY - zombiePos->position_.y;
    float radiusDif = playerRadius + attackRadius;
    // if collide
    if (fabs(((posXDif * posXDif) + (posYDif * posYDif))) <= (radiusDif * radiusDif)) {
        return true;
    }
    return false;

}
