#ifndef SRC_COMPONENTS_UI_ROW_POSITION_COMPONENT_H
#define SRC_COMPONENTS_UI_ROW_POSITION_COMPONENT_H

#include <raylib-cpp.hpp>

struct RowPositionComponent {
    float value_;
    RowPositionComponent(float value) : value_(value) {}
};

#endif // SRC_COMPONENTS_UI_ROW_POSITION_COMPONENT_H
