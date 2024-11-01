#include "MenuControlSystem.h"
#include <iostream>

void MenuControlSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Menu Control System Initialized" << std::endl;
}

void MenuControlSystem::Draw(std::vector<Entity*> *entities) {
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
                DrawMenuItem(entity, menu, menuItem);
            }
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


void MenuControlSystem::DrawTextLine(const char *text, Vector2 pos, MenuComponent *menu) {
    DrawTextEx(
        GetFontDefault(),
        text,
        pos,
        menu->textSize_,
        menu->textSpacing_,
        menu->color_
    );
}

void MenuControlSystem::DrawMenuItem(Entity *uiElement, MenuComponent *menu, MenuItemComponent *menuItem) {
    BaseUIComponent *baseUI = uiElement->GetComponent<BaseUIComponent>();
    
    if (menuItem->menuItemIndex_ == menu->currentItemIndex_) {
        DrawRectangle(
            baseUI->position_.x * menuItem->col_,
            baseUI->position_.y + menu->textSize_ * menuItem->row_,
            menuItem->text_.length() * 10.0f,
            menu->textSize_,
            menu->selectedColor_
        );
    }
    DrawTextLine(
        menuItem->text_.c_str(),
        (Vector2){
            baseUI->position_.x + menuItem->col_,
            baseUI->position_.y + (menu->textSize_ * menuItem->row_)
        },
        menu
    );
}
