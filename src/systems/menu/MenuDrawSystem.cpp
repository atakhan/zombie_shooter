#include "MenuDrawSystem.h"
#include <iostream>

void MenuDrawSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Menu Draw System Initialized" << std::endl;
}

void MenuDrawSystem::Draw(std::vector<Entity*> *entities) {}

void MenuDrawSystem::Update(std::vector<Entity*> *entities) {
    MenuComponent *menu = nullptr;
    int currentItemIndex = 0;
    for (auto& entity : *entities) {
        if (entity->HasComponent<MenuComponent>()) {
            menu = entity->GetComponent<MenuComponent>();
        }
    }

    if (menu) {
        for (auto& entity : *entities) {
            MenuItemComponent *menuItem = entity->GetComponent<MenuItemComponent>();
            BaseUIComponent *baseUi = entity->GetComponent<BaseUIComponent>();
            if (menuItem && baseUi) {
                MenuTools::DrawMenuItem(entity, menu, menuItem);
            }
        }
    }


}

