#ifndef SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_ITEM_COMPONENT_H
#define SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_ITEM_COMPONENT_H

#include <raylib-cpp.hpp>
#include <string>

struct MenuItemComponent {
    int menuItemIndex_;
    std::string text_;
    float row_;
    float col_;

    MenuItemComponent(int menuItemIndex, std::string text, float row, float col) 
        : menuItemIndex_(menuItemIndex)
        , text_(text)
        , row_(row)
        , col_(col)
        {}
};

#endif // SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_ITEM_COMPONENT_H
