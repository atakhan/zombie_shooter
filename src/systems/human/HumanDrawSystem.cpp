#include "HumanDrawSystem.h"
#include <iostream>

void HumanDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Human Draw System Initialized" << std::endl;
}

void HumanDrawSystem::Update(std::vector<Entity*> *entities) {}

void HumanDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity->HasComponent<HumanComponent>()) {
            HumanComponent* human = entity->GetComponent<HumanComponent>();
            PositionComponent* position = entity->GetComponent<PositionComponent>();
            HealthComponent* health = entity->GetComponent<HealthComponent>();
            SoundComponent* sound = entity->GetComponent<SoundComponent>();

            if (position && health) {
                DrawBody(position, health, human->isAlive);
            }
            if (position && sound) {
                DrawMessArea(position, sound);
            }
            if (position && health) {
                DrawHumanInfo(entity);
            }
        }
    }    
}

void HumanDrawSystem::DrawBody(PositionComponent* position, HealthComponent* health, bool isAlive) {
    Color bodyColor = Config::HUMAN_COLOR;
    if (!isAlive) {
        bodyColor = Config::ZOMBIE_COLOR;
    }
    DrawCircle(
        position->position_.x,
        position->position_.y,
        health->health_,
        bodyColor
    );
}

void HumanDrawSystem::DrawMessArea(PositionComponent* position, SoundComponent* sound) {
    DrawCircle(
        position->position_.x,
        position->position_.y,
        sound->currentRadius,
        Config::SOUND_RADIUS_COLOR
    );
}

void HumanDrawSystem::DrawHumanInfo(Entity *entity) {
    HumanComponent* human = entity->GetComponent<HumanComponent>();
    PositionComponent* position = entity->GetComponent<PositionComponent>();
    HealthComponent* health = entity->GetComponent<HealthComponent>();
    SoundComponent* sound = entity->GetComponent<SoundComponent>();
    TargetComponent* target = entity->GetComponent<TargetComponent>();
    StaminaComponent* stamina = entity->GetComponent<StaminaComponent>();
    
    Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_,
        1, "alive: ", (human->isAlive) ? "YES" : "NO"
    );
    
    std::string statusText;
    if (human->currentStatus == HumanComponent::Status::SLEEP) statusText = "SLEEP";
    if (human->currentStatus == HumanComponent::Status::IDLE) statusText = "IDLE";
    if (human->currentStatus == HumanComponent::Status::LOOT) statusText = "LOOT";
    if (human->currentStatus == HumanComponent::Status::WALK) statusText = "WALK";
    if (human->currentStatus == HumanComponent::Status::RUN) statusText = "RUN";
    if (human->currentStatus == HumanComponent::Status::ATTACK) statusText = "ATTACK";
    Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_,
        2, "status: ", statusText
    );
    
    Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_,
        3, "stamina: ", std::to_string(stamina->currentValue_)
    );
    
    Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
        4, "current pos: ", std::to_string(position->position_.x) + ", " + std::to_string(position->position_.y)
    );
    
    Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
        5, "target: ", std::to_string(target->position_.x) + ", " + std::to_string(target->position_.y)
    );
    
    Ui::DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, position->position_, health->health_, 
        6, "target status: ", std::to_string(target->active_)
    );
}
