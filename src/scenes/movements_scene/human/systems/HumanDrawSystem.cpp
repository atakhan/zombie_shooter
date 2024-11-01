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
            if (human) {
                DrawBody(human);
                DrawHumanInfo(entity);
            }
        }
    }    
}

void HumanDrawSystem::DrawBody(HumanComponent *human) {
    Color bodyColor = Config::HUMAN_COLOR;
    if (!human->isAlive_) {
        bodyColor = Config::ZOMBIE_COLOR;
    }
    DrawCircle(
        human->position_.x,
        human->position_.y,
        human->health_,
        bodyColor
    );
}

void HumanDrawSystem::DrawHumanInfo(Entity *entity) {
    HumanComponent* human = entity->GetComponent<HumanComponent>();
    
    DEBUG_DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, human->position_, human->health_,
        1, "alive: ", (human->isAlive_) ? "YES" : "NO"
    );
    
    std::string statusText;
    if (human->currentStatus_ == HumanComponent::Status::SLEEP) statusText = "SLEEP";
    if (human->currentStatus_ == HumanComponent::Status::IDLE) statusText = "IDLE";
    if (human->currentStatus_ == HumanComponent::Status::LOOT) statusText = "LOOT";
    if (human->currentStatus_ == HumanComponent::Status::WALK) statusText = "WALK";
    if (human->currentStatus_ == HumanComponent::Status::RUN) statusText = "RUN";
    if (human->currentStatus_ == HumanComponent::Status::ATTACK) statusText = "ATTACK";
    DEBUG_DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, human->position_, human->health_,
        2, "status: ", statusText
    );
    
    DEBUG_DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, human->position_, human->health_, 
        4, "current pos: ", std::to_string(human->position_.x) + ", " + std::to_string(human->position_.y)
    );
    
    DEBUG_DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, human->position_, human->health_, 
        5, "target: ", std::to_string(human->target_.x) + ", " + std::to_string(human->target_.y)
    );
    
    DEBUG_DrawTitleValueText(Config::DEFAULT_UI_TEXT_COLOR, human->position_, human->health_, 
        6, "target status: ", std::to_string(human->isTargetReached_)
    );
}

void HumanDrawSystem::DEBUG_DrawTitleValueText(Color color, Vector2 position, float padding, float rowNum, std::string title, std::string value) {
    float textSize = 16.0f;
    float textSpacing = 1.0f;
    std::string text =  title + ": " + value;
    DrawTextEx(
        GetFontDefault(),
        text.c_str(),
        (Vector2){
            position.x + padding,
            position.y + padding + textSize * rowNum
        },
        textSize,
        textSpacing,
        color
    );
}