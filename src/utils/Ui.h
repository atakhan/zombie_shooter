#ifndef UTILS_UI_H
#define UTILS_UI_H

#include <raylib-cpp.hpp>

class Ui {  
  public:
    static void DrawTitleValueText(Color color, Vector2 position, float padding, float rowNum, std::string title, std::string value) {
        float textSize = 16.0f;
        float textSpacing = 1.0f;
        std::string text =  title + ": " + value;
        DrawTextEx(
            GetFontDefault(),
            text.c_str(),
            (Vector2){
                position.x + padding,
                position.y + padding + textSize * rowNum
            },
            textSize,
            textSpacing,
            color
        );
    }
};

#endif // UTILS_UI_H