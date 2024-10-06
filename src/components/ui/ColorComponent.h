// TextComponent.h
#ifndef SRC_COMPONENTS_UI_COLOR_COMPONENT_H
#define SRC_COMPONENTS_UI_COLOR_COMPONENT_H

#include <raylib-cpp.hpp>

struct ColorComponent {
    Color value_;
    ColorComponent(Color color) : value_(color) {}
};

#endif // SRC_COMPONENTS_UI_COLOR_COMPONENT_H
