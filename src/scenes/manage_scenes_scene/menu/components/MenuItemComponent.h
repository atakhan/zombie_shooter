#ifndef SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_ITEM_COMPONENT_H
#define SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_ITEM_COMPONENT_H

#include <raylib-cpp.hpp>

struct MenuItemComponent {
    int menuItemIndex_;
    MenuItemComponent(int menuItemIndex) : menuItemIndex_(menuItemIndex) {}
};

#endif // SRC_SCENES_MANAGE_SCENES_SCENE_MENU_COMPONENTS_MENU_ITEM_COMPONENT_H
