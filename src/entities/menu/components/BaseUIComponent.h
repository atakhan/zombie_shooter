// BaseUIComponent.h
#ifndef SRC_ENTITIES_MENU_COMPONENTS_BASE_UI_COMPONENT_H
#define SRC_ENTITIES_MENU_COMPONENTS_BASE_UI_COMPONENT_H

#include <raylib-cpp.hpp>

struct BaseUIComponent {
    bool isActive;
    Vector2 position_;

    BaseUIComponent() : isActive(true) {}
    BaseUIComponent(float x, float y)
        : position_((Vector2){x, y})
        , isActive(true)
        {}
    BaseUIComponent(Vector2 pos) 
        : position_(pos)
        , isActive(true)
        {}
};

#endif // SRC_ENTITIES_MENU_COMPONENTS_BASE_UI_COMPONENT_H
