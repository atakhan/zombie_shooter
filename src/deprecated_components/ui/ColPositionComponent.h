#ifndef SRC_COMPONENTS_UI_COL_POSITION_COMPONENT_H
#define SRC_COMPONENTS_UI_COL_POSITION_COMPONENT_H

#include <raylib-cpp.hpp>

struct ColPositionComponent {
    float value_;
    ColPositionComponent(float value) : value_(value) {}
};

#endif // SRC_COMPONENTS_UI_COL_POSITION_COMPONENT_H
