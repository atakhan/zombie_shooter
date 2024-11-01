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


void MenuControlSystem::DrawMenuItem(Entity *uiElement, MenuComponent *menu, MenuItemComponent *menuItem) {
        BaseUIComponent *baseUI = uiElement->GetComponent<BaseUIComponent>();
        TextComponent *text = uiElement->GetComponent<TextComponent>();
        ColPositionComponent *colNum = uiElement->GetComponent<ColPositionComponent>();
        RowPositionComponent *rowNum = uiElement->GetComponent<RowPositionComponent>();
        
        if (menuItem->menuItemIndex_ == menu->currentItemIndex_) {
            DrawRectangle(
                baseUI->position_.x * colNum->value_,
                baseUI->position_.y + menu->textSize_ * rowNum->value_,
                text->text_.length() * 10.0f,
                menu->textSize_,
                GREEN
            );
        }
        UiTools::DrawTextLine(
            text->text_.c_str(),
            (Vector2){
                position->position_.x + colNum->value_,
                position->position_.y + (menu->textSize_ * rowNum->value_)
            },
            menu
        );
    }
