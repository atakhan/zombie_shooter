#include "MenuControlSystem.h"
#include <iostream>

void MenuControlSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Menu Control System Initialized" << std::endl;
}

void MenuControlSystem::Draw(std::vector<Entity*> *entities) {}

void MenuControlSystem::Update(std::vector<Entity*> *entities) {
    // // Example of using GetEntityByComponent() method
    // Entity *terrain = GetEntityByComponent<TerrainComponent>(entities);
    // if (terrain == nullptr) { return; }
    
    // TODO? menu should be an entity
    MenuComponent *menu = nullptr;
    int currentItemIndex = 0;
    for (auto& entity : *entities) {
        if (entity->HasComponent<MenuComponent>()) {
            menu = entity->GetComponent<MenuComponent>();
        }
    }

    if (menu) {
        int menuItemsCount = 0;
        for (auto& entity : *entities) {
            if (entity->HasComponent<MenuItemComponent>()) {
                if (entity->HasComponent<BaseUIComponent>()) {
                    menuItemsCount++;
                }
            }
        }

        if (IsKeyReleased(KEY_UP)) {
            std::cout << "KEY UP PRESSED" << std::endl;
            int currentIndex = menu->currentItemIndex_;
            int newIndex = menu->currentItemIndex_ - 1;
            std::cout << "oldIndex: " << currentIndex << "; newIndex: " << newIndex << std::endl;
            menu->currentItemIndex_ = (newIndex < 0) ? menuItemsCount-1 : newIndex;
        } else
        if (IsKeyReleased(KEY_DOWN)) {
            std::cout << "KEY DOWN PRESSED" << std::endl;
            int currentIndex = menu->currentItemIndex_;
            int newIndex = menu->currentItemIndex_ + 1;
            std::cout << "oldIndex: " << currentIndex << "; newIndex: " << newIndex << std::endl;
            menu->currentItemIndex_ = (newIndex >= menuItemsCount) ? 0 : newIndex;
        } else
        if (IsKeyReleased(KEY_ENTER)) {
            std::cout << "KEY ENTER PRESSED" << std::endl;
            int currentIndex = menu->currentItemIndex_;
            menu->chooseEvent_ = true;
            std::cout << "currentIndex: " << currentIndex << std::endl;
        }
    }

}


