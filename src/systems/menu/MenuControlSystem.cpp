#include "MenuControlSystem.h"
#include <iostream>

void MenuControlSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Menu Control System Initialized" << std::endl;
}

void MenuControlSystem::Draw(std::vector<Entity*> *entities) {}

void MenuControlSystem::Update(std::vector<Entity*> *entities) {
    MenuComponent *menu = nullptr;
    int currentItemIndex = 0;
    for (auto& entity : *entities) {
        if (entity->HasComponent<MenuComponent>()) {
            menu = entity->GetComponent<MenuComponent>();
        }
    }

    int menuItemsCount = 0;
    for (auto& entity : *entities) {
        if (entity->HasComponent<MenuItemComponent>()) {
            if (entity->HasComponent<BaseUIComponent>()) {
                menuItemsCount++;
            }
        }
    }

    if (menu) {
        if (IsKeyReleased(KEY_UP)) {
            std::cout << "KEY UP PRESSED" << std::endl;
            std::cout << menu->currentItemIndex << std::endl;
            menu->currentItemIndex = ((menu->currentItemIndex - 1) < 0) ? menuItemsCount : (menu->currentItemIndex - 1);
        } else
        if (IsKeyReleased(KEY_DOWN)) {
            std::cout << "KEY DOWN PRESSED" << std::endl;
            std::cout << menu->currentItemIndex << std::endl;
            menu->currentItemIndex = ((menu->currentItemIndex + 1) > menuItemsCount) ? 0 : (menu->currentItemIndex + 1);
        }
    }

}


