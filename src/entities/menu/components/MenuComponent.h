#ifndef SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_COMPONENT_H
#define SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_COMPONENT_H

#include <raylib-cpp.hpp>

struct MenuComponent {
    unsigned int menuIndex_;
    bool chooseEvent_;
    int currentItemIndex_;
    float textSize_;
    float textSpacing_;
    float lineSpacing_;
    Color color_;
    Color selectedColor_;
    Vector2 position_;

    MenuComponent(unsigned int menuIndex, float size, float textSpacing, float lineSpacing, Color color, Color selected, Vector2 pos) 
        : menuIndex_(menuIndex)
        , currentItemIndex_(0) 
        , chooseEvent_(false) 
        , textSize_(size) 
        , textSpacing_(textSpacing) 
        , lineSpacing_(lineSpacing) 
        , color_(color)
        , selectedColor_(selected)
        , position_(pos)
        {}
};

#endif // SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_COMPONENT_H
