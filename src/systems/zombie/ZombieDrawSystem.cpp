#include "ZombieDrawSystem.h"
#include <iostream>

void ZombieDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Zombie Draw System Initialized" << std::endl;
}

void ZombieDrawSystem::Update(std::vector<Entity*> *entities) {}

void ZombieDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<ZombieComponent>()) {
            ZombieComponent *zombie = entity->GetComponent<ZombieComponent>();
            PositionComponent *position = entity->GetComponent<PositionComponent>();
            HealthComponent *health = entity->GetComponent<HealthComponent>();
            SoundComponent *sound = entity->GetComponent<SoundComponent>();
            TargetComponent *target = entity->GetComponent<TargetComponent>();

            if (position && health && sound) {
                DrawCircle(
                    position->position_.x,
                    position->position_.y,
                    sound->currentRadius,
                    Config::SOUND_RADIUS_COLOR
                );
                DrawCircle(
                    position->position_.x,
                    position->position_.y,
                    health->health_,
                    Config::ZOMBIE_COLOR
                );
                
                DrawCircle(
                    target->position_.x,
                    target->position_.y,
                    5.0f, Config::TARGET_COLOR
                );

                DrawLine(
                    position->position_.x, 
                    position->position_.y,
                    target->position_.x,
                    target->position_.y,
                    Config::PATH_COLOR
                );

                Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
                    1, "current pos: ", std::to_string(position->position_.x) + ", " + std::to_string(position->position_.y)
                );
                
                Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
                    2, "target: ", std::to_string(target->position_.x) + ", " + std::to_string(target->position_.y)
                );
                
                Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
                    3, "target status: ", std::to_string(target->active_)
                );
            }
        }
        
    }
}

