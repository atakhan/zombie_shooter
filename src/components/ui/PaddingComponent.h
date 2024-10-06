#ifndef SRC_COMPONENTS_UI_PADDING_COMPONENT_H
#define SRC_COMPONENTS_UI_PADDING_COMPONENT_H

#include <raylib-cpp.hpp>

struct PaddingComponent {
    float value_;
    PaddingComponent(float value) : value_(value) {}
};

#endif // SRC_COMPONENTS_UI_PADDING_COMPONENT_H
