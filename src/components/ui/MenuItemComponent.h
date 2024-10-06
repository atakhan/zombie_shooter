#ifndef SRC_COMPONENTS_UI_MENU_ITEM_COMPONENT_H
#define SRC_COMPONENTS_UI_MENU_ITEM_COMPONENT_H

#include <raylib-cpp.hpp>

struct MenuItemComponent {
    int menuItemIndex_;
    MenuItemComponent(int menuItemIndex) : menuItemIndex_(menuItemIndex) {}
};

#endif // SRC_COMPONENTS_UI_MENU_ITEM_COMPONENT_H
