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
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue;
        }
        if (entity->HasComponent<ZombieComponent>()) {
            ZombieComponent* zombie_component = entity->GetComponent<ZombieComponent>();
            
            PositionComponent* zombie_position = nullptr;
            HealthComponent* zombie_health = nullptr;
            SoundComponent* zombie_sound = nullptr;
            TargetComponent* target = nullptr;
            if (entity->HasComponent<PositionComponent>()) {
                zombie_position = entity->GetComponent<PositionComponent>();
            }
            if (entity->HasComponent<HealthComponent>()) {
                zombie_health = entity->GetComponent<HealthComponent>();
            }
            if (entity->HasComponent<SoundComponent>()) {
                zombie_sound = entity->GetComponent<SoundComponent>();
            }
            if (entity->HasComponent<TargetComponent>()) {
                target = entity->GetComponent<TargetComponent>();
            }

            if (zombie_position && zombie_health && zombie_sound) {
                PositionComponent* food = nullptr; 
                food = FindFood(zombie_position, zombie_health, player);
                if (food) {
                    target->position_ = food->position_;
                    zombie_component->currentState = ZombieComponent::Status::RUN;
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

PositionComponent *ZombieMoveSystem::FindFood(PositionComponent zombie_position, HealthComponent zombie_radius, Entity *player) {
    PositionComponent *result = nullptr;

    PositionComponent *player_position = nullptr;
    HealthComponent *player_radius = nullptr;
    if (player->HasComponent<PositionComponent>()) {
        player_position = player->GetComponent<PositionComponent>();
    }
    if (player->HasComponent<HealthComponent>()) {
        player_radius = player->GetComponent<HealthComponent>();
    }
    float player_pos_x = player_position->position_.x;
    float player_pos_y = player_position->position_.y;

    PositionComponent *zombie_position = nullptr;
    HealthComponent *zombie_radius = nullptr;
    if (zombie->HasComponent<PositionComponent>()) {
        zombie_position = zombie->GetComponent<PositionComponent>();
    }
    if (zombie->HasComponent<HealthComponent>()) {
        zombie_radius = zombie->GetComponent<HealthComponent>();
    }
    float zombie_pos_x = zombie_position->position_.x;
    float zombie_pos_y = zombie_position->position_.y;



    float pos_x_dif = player_pos_x - zombie_pos_x;
    float pos_y_dif = player_pos_y - zombie_pos_y;

    float radius_dif = player_radius->health_ + zombie_radius->health_;
    // if collide
    if (fabs(((pos_x_dif * pos_x_dif) + (pos_y_dif * pos_y_dif))) <= (radius_dif * radius_dif)) {
        if (!result) {
            result = new PositionComponent(player_pos_x, player_pos_y);
        }
    }

    return result;
}

