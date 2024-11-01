#include "ZombieMoveSystem.h"

void ZombieMoveSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie Draw System Initialized" << std::endl;
}

void ZombieMoveSystem::Draw(std::vector<Entity*> *entities) {}

void ZombieMoveSystem::Update(std::vector<Entity*> *entities) {
    Entity *player = GetEntityByComponent<PlayerComponent>(entities);
    
    PositionComponent* playerPosition = player->GetComponent<PositionComponent>();
    SoundComponent* playerSound = playerSound = player->GetComponent<SoundComponent>();
    HealthComponent* playerHealth = player->GetComponent<HealthComponent>();

    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue;
        }
        if (entity->HasComponent<ZombieComponent>()) {
            ZombieComponent* zombieComponent = entity->GetComponent<ZombieComponent>();
            PositionComponent* zombiePosition = entity->GetComponent<PositionComponent>();
            HealthComponent* zombieRadius = entity->GetComponent<HealthComponent>();
            TargetComponent* target = entity->GetComponent<TargetComponent>();
            SpeedComponent* speed = entity->GetComponent<SpeedComponent>();
            AttackComponent* attack = entity->GetComponent<AttackComponent>();

            if (zombiePosition && zombieRadius && target && playerPosition && playerSound) {
                if (target->active_) {
                    if (zombieComponent->currentState == ZombieComponent::Status::WALK) {
                        MoveTo(target, zombiePosition, speed->speed_ * Config::ZOMBIE_WALK_COEF);
                    } else
                    if (zombieComponent->currentState == ZombieComponent::Status::RUN) {
                        MoveTo(target, zombiePosition, speed->speed_ * Config::ZOMBIE_RUN_COEF);
                    }
                }
            }
        }
    }
}

void ZombieMoveSystem::MoveTo(TargetComponent *targetPos, PositionComponent *curPos, float speed) {
    float distanceX = targetPos->position_.x - curPos->position_.x;
    float distanceY = targetPos->position_.y - curPos->position_.y;
    float distance = std::sqrt(std::pow(distanceX, 2) + std::pow(distanceY, 2));

    if (Config::HUMAN_MOVE_TRESHOLD < distance) {
        Vector2 direction = { distanceX / distance, distanceY / distance };
        curPos->position_.x += direction.x * speed;
        curPos->position_.y += direction.y * speed;
        // std::cout << "Moving towards target: (" << curPos->position_.x << ", " << curPos->position_.y << ")" << std::endl;
    }
}
