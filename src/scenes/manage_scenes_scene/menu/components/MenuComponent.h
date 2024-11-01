#ifndef SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_COMPONENT_H
#define SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_COMPONENT_H

#include <raylib-cpp.hpp>

struct MenuComponent {
    bool chooseEvent_;
    int currentItemIndex_;
    float textSize_;
    float textSpacing_;
    float lineSpacing_;
    Color color_;

    MenuComponent(float size, float textSpacing, float lineSpacing, Color color) 
        : currentItemIndex_(0) 
        , chooseEvent_(false) 
        , textSize_(size) 
        , textSpacing_(textSpacing) 
        , lineSpacing_(lineSpacing) 
        , color_(color)
        {}
};

#endif // SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_COMPONENT_H
