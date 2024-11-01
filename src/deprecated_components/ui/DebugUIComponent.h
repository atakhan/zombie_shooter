#ifndef SRC_COMPONENTS_DEBUG_COMPONENT_H
#define SRC_COMPONENTS_DEBUG_COMPONENT_H

struct DebugUIComponent {
    bool isVisible_;

    DebugUIComponent()
        : isVisible_(false)
    {}
};

#endif // SRC_COMPONENTS_DEBUG_COMPONENT_H
