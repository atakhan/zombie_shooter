#include "UIDrawSystem.h"
#include <iostream>

void UIDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "UIDrawSystem Initialized" << std::endl;
}

void UIDrawSystem::Update(std::vector<Entity*> *entities) {}

void UIDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cout << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<BaseUIComponent>()) {
            BaseUIComponent *baseUi = entity->GetComponent<BaseUIComponent>();
            if (baseUi) {
                UiTools::DrawUIEntity(entity);
            }
        }
        
    }
}

