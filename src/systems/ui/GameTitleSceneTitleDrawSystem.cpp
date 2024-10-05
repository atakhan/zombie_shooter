#include "GameTitleSceneTitleDrawSystem.h"
#include <iostream>

void GameTitleSceneTitleDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "GameTitleSceneTitleDrawSystem Initialized" << std::endl;
}

void GameTitleSceneTitleDrawSystem::Update(std::vector<Entity*> *entities) {}

void GameTitleSceneTitleDrawSystem::Draw(std::vector<Entity*> *entities) {
    for (auto& entity : *entities) {
        if (entity == nullptr) {
            std::cerr << "Entity pointer is null!" << std::endl;
            continue; // Skip this iteration
        }
        if (entity->HasComponent<GameComponent>()) {
            GameComponent *gameTitles = entity->GetComponent<GameComponent>();
            
            if (gameTitles) {
                Ui::DrawTitleValueText(
                    R4G0B0A7, (Vector2){10.0f, 10.0f}, 10.0f, 
                    1, gameTitles->title, gameTitles->currentSceneTitle
                );
            }
        }
        
    }
}

