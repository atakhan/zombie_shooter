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

};

#endif // SRC_UTILS_MENU_TOOLS_H