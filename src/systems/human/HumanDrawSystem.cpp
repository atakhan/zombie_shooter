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
            HumanPhysiologicalComponent* physiology = entity->GetComponent<HumanPhysiologicalComponent>();
            HumanBreathComponent* breath = entity->GetComponent<HumanBreathComponent>();

            if (position && health) {
                DrawBody(position, health, human->isAlive);
            }
            if (position && sound) {
                DrawMessArea(position, sound);
            }
            if (position && health && physiology && breath) {
                DrawHumanInfo(human, position, health, physiology, breath);
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

void HumanDrawSystem::DrawHumanInfo(HumanComponent *human, PositionComponent* position, HealthComponent* health, HumanPhysiologicalComponent* physiology, HumanBreathComponent* breath) {
    std::string statusText;
    if (human->currentStatus == HumanComponent::Status::SLEEP) statusText = "SLEEP";
    if (human->currentStatus == HumanComponent::Status::IDLE) statusText = "IDLE";
    if (human->currentStatus == HumanComponent::Status::LOOT) statusText = "LOOT";
    if (human->currentStatus == HumanComponent::Status::WALK) statusText = "WALK";
    if (human->currentStatus == HumanComponent::Status::RUN) statusText = "RUN";
    if (human->currentStatus == HumanComponent::Status::ATTACK) statusText = "ATTACK";
    DrawTitleValueText(
        new PositionComponent(
            position->position_.x + health->health_,
            position->position_.y + health->health_ + (Config::NEEDS_INFO_TEXT_SIZE * 1)
        ),
        "status: ", statusText
    );
    if (physiology->air_) {
        DrawTitleValueText(
            new PositionComponent(
                position->position_.x + health->health_,
                position->position_.y + health->health_ + (Config::NEEDS_INFO_TEXT_SIZE * 2)
            ),
            "air", std::to_string(physiology->air_)
        );
        DrawTitleValueText(
            new PositionComponent(
                position->position_.x + health->health_,
                position->position_.y + health->health_ + (Config::NEEDS_INFO_TEXT_SIZE * 3)
            ),
            "breath", std::to_string(breath->inhaleValue)
        );
    }
}

void HumanDrawSystem::DrawTitleValueText(PositionComponent* position, std::string title, std::string value) {
    std::string text =  title + ": " + value;
    DrawTextEx(
        GetFontDefault(),
        text.c_str(),
        position->position_,
        Config::NEEDS_INFO_TEXT_SIZE,
        Config::NEEDS_INFO_TEXT_SPACING,
        Config::NEEDS_INFO_TEXT_COLOR
    );
}