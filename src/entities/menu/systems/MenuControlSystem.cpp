#include "MenuControlSystem.h"
#include <iostream>

void MenuControlSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Menu Control System Initialized" << std::endl;
}

void MenuControlSystem::Draw(std::vector<Entity*> *entities) {

    for (auto& entity : *entities) {
        MenuComponent *menu = entity->GetComponent<MenuComponent>();
        
        if (menu) {
            for (auto& entity : *entities) {
                MenuItemComponent *menuItem = entity->GetComponent<MenuItemComponent>();
                if (menuItem) {
                    if (menu->menuIndex_ == menuItem->menuIndex_) {
                        BaseUIComponent *baseUi = entity->GetComponent<BaseUIComponent>();
                        if (menuItem && menu && baseUi) {
                            std::cout << "all components found: lets draw menu item" << std::endl;
                            Tools::DrawMenuItem(baseUi, menu, menuItem);
                        } else {
                            std::cout << "BaseUIComponent not found" << std::endl;
                        }
                    }
                } else {
                    std::cout << "MenuItemComponent not found" << std::endl;
                }
            }
        } else {
            std::cout << "MenuComponent not found" << std::endl;
        }

    }
}

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
            
            int currentIndex = menu->currentItemIndex_;
            int newIndex = menu->currentItemIndex_ - 1;
            menu->currentItemIndex_ = (newIndex < 0) ? menuItemsCount-1 : newIndex;
        } else
        if (IsKeyReleased(KEY_DOWN)) {
            int currentIndex = menu->currentItemIndex_;
            int newIndex = menu->currentItemIndex_ + 1;
            menu->currentItemIndex_ = (newIndex >= menuItemsCount) ? 0 : newIndex;
        } else
        if (IsKeyReleased(KEY_ENTER)) {
            int currentIndex = menu->currentItemIndex_;
            menu->chooseEvent_ = true;
        }
    }

}
