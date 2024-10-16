#ifndef SRC_UTILS_MENU_TOOLS_H
#define SRC_UTILS_MENU_TOOLS_H

#include <string>
#include "../Config.h"
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"
#include "UiTools.h"

class MenuTools {  
  public:
    // CREATE GAME
    static Entity* CreateMenu(Vector2 pos, float fontSize, float textSpacing, float lineSpacing, Color color) {
        Entity *game = new Entity();
        game->AddComponent<MenuComponent>(MenuComponent(
            fontSize,
            textSpacing,
            lineSpacing,
            color
        ));
        game->AddComponent<PositionComponent>(PositionComponent(pos));
        return game;
    }

    static void DrawMenuItem(Entity *uiElement, MenuComponent *menu, MenuItemComponent *menuItem) {
        PositionComponent *position = uiElement->GetComponent<PositionComponent>();
        TextComponent *text = uiElement->GetComponent<TextComponent>();
        ColPositionComponent *colNum = uiElement->GetComponent<ColPositionComponent>();
        RowPositionComponent *rowNum = uiElement->GetComponent<RowPositionComponent>();
        
        if (menuItem->menuItemIndex_ == menu->currentItemIndex_) {
            DrawRectangle(
                position->position_.x * colNum->value_,
                position->position_.y + menu->textSize_ * rowNum->value_,
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

    static Entity* CreateMenuItem(
            int index, 
            Entity *menuEntity,
            std::string text,
            float colPos, 
            float rowPos 
    ) {
        Entity *element = nullptr;
        MenuComponent *menu = menuEntity->GetComponent<MenuComponent>();
        PositionComponent *menuPos = menuEntity->GetComponent<PositionComponent>();

        if (menu && menuPos) {
            element = UiTools::CreateUITextEntity(
                (Vector2){
                    menuPos->position_.x * colPos, 
                    menuPos->position_.y + (menu->lineSpacing_ * rowPos)
                },
                text,
                menu->textSize_,
                colPos,
                rowPos,
                menu->textSpacing_,
                menu->color_
            );
            element->AddComponent<MenuItemComponent>(
                MenuItemComponent(index)
            );
        }

        return element;
    }

};

#endif // SRC_UTILS_MENU_TOOLS_H