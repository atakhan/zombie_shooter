#ifndef SRC_COMPONENTS_UI_TEXT_SPACING_COMPONENT_H
#define SRC_COMPONENTS_UI_TEXT_SPACING_COMPONENT_H

#include <raylib-cpp.hpp>

struct TextSpacingComponent {
    float value_;
    TextSpacingComponent(float value) : value_(value) {}
};

#endif // SRC_COMPONENTS_UI_TEXT_SPACING_COMPONENT_H
