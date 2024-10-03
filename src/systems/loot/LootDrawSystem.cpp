#include "LootDrawSystem.h"
#include <iostream>

void LootDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Human Draw System Initialized" << std::endl;
}

void LootDrawSystem::Update(std::vector<Entity*> *entities) {}

void LootDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<LootComponent>()) {
            LootComponent* loot = nullptr;
            
            PositionComponent* position = entity->GetComponent<PositionComponent>();
            SmellComponent* smell = entity->GetComponent<SmellComponent>();
            
            if (position && smell) {
                DrawCircle(
                    position->position_.x,
                    position->position_.y,
                    smell->currentRadius,
                    Config::SMELL_RADIUS_COLOR
                );
                DrawCircle(
                    position->position_.x,
                    position->position_.y,
                    loot->amount * GetLootSize(loot->current),
                    Config::ZOMBIE_COLOR
                );
            }
        }
        
    }
}

float LootDrawSystem::GetLootSize(LootComponent::Type type) {
    if (type == LootComponent::Type::FOOD) {
        return Config::FOOD_DEFAULT_SIZE;
    }

    return 0.1f;
}
