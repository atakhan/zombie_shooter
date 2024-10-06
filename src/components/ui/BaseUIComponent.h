// BaseUIComponent.h
#ifndef SRC_COMPONENTS_UI_BASE_UI_COMPONENT_H
#define SRC_COMPONENTS_UI_BASE_UI_COMPONENT_H

#include <raylib-cpp.hpp>

struct BaseUIComponent {
    bool isActive;
    BaseUIComponent() : isActive(true) {}
};

#endif // SRC_COMPONENTS_UI_BASE_UI_COMPONENT_H
