#ifndef SRC_COMPONENTS_UI_TEXT_COMPONENT_H
#define SRC_COMPONENTS_UI_TEXT_COMPONENT_H

#include <raylib-cpp.hpp>

struct TextComponent {
    std::string text_;
    TextComponent(std::string text) : text_(text) {}
};

#endif // SRC_COMPONENTS_UI_TEXT_COMPONENT_H
