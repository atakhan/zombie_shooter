#ifndef SRC_COMPONENTS_UI_TEXT_HIGHLIGHT_COMPONENT_H
#define SRC_COMPONENTS_UI_TEXT_HIGHLIGHT_COMPONENT_H

#include <raylib-cpp.hpp>

struct TextHighlightComponent {
    bool active_;
    TextHighlightComponent(bool value) : active_(value) {}
};

#endif // SRC_COMPONENTS_UI_TEXT_HIGHLIGHT_COMPONENT_H
