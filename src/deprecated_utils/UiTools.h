#ifndef SRC_UTILS_UI_TOOLS_H
#define SRC_UTILS_UI_TOOLS_H

#include <raylib-cpp.hpp>
#include <string>

#include "../Config.h"
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"

class UiTools {  
  public:
    static void DrawTextLine(const char *text, Vector2 pos, MenuComponent *menu) {
        DrawTextEx(
            GetFontDefault(),
            text,
            pos,
            menu->textSize_,
            menu->textSpacing_,
            menu->color_
        );
    }

    // static Entity* CreateUITextEntity(
    //         Vector2 pos, 
    //         std::string text,
    //         float textSize, 
    //         float colPos, 
    //         float rowPos, 
    //         float textSpacing, 
    //         Color color
    // ) {
    //     Entity *element = new Entity();
    //     element->AddComponent<BaseUIComponent>(BaseUIComponent());
    //     element->AddComponent<PositionComponent>(PositionComponent(pos));
    //     element->AddComponent<TextComponent>(TextComponent(text));
    //     element->AddComponent<TextSizeComponent>(TextSizeComponent(textSize));
    //     element->AddComponent<ColPositionComponent>(ColPositionComponent(colPos));
    //     element->AddComponent<RowPositionComponent>(RowPositionComponent(rowPos));
    //     element->AddComponent<TextSpacingComponent>(TextSpacingComponent(textSpacing));
    //     element->AddComponent<ColorComponent>(ColorComponent(color));
    //     element->AddComponent<TextHighlightComponent>(TextHighlightComponent(false));

    //     return element;
    // }

    // static void DrawUITextEntity(Entity *uiElement) {
    //     PositionComponent *position = uiElement->GetComponent<PositionComponent>();
    //     TextComponent *text = uiElement->GetComponent<TextComponent>();
    //     TextSizeComponent *textSize = uiElement->GetComponent<TextSizeComponent>();
    //     ColPositionComponent *colNum = uiElement->GetComponent<ColPositionComponent>();
    //     RowPositionComponent *rowNum = uiElement->GetComponent<RowPositionComponent>();
    //     TextSpacingComponent *textSpacing = uiElement->GetComponent<TextSpacingComponent>();
    //     ColorComponent *color = uiElement->GetComponent<ColorComponent>();
    //     // PaddingComponent *padding = uiElement->GetComponent<PaddingComponent>();

    //     if (position && text && textSize && colNum && rowNum && textSpacing && color) {
    //         DrawTextEx(
    //             GetFontDefault(),
    //             text->text_.c_str(),
    //             (Vector2){
    //                 position->position_.x * colNum->value_,
    //                 position->position_.y + textSize->value_ * rowNum->value_
    //             },
    //             textSize->value_,
    //             textSpacing->value_,
    //             color->value_
    //         );
    //     }
    // }
};

#endif // SRC_UTILS_UI_TOOLS_H