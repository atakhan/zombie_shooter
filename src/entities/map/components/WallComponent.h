#ifndef SRC_COMPONENTS_WALL_COMPONENT_H
#define SRC_COMPONENTS_WALL_COMPONENT_H

#include <raylib-cpp.hpp>

struct WallComponent {
    bool isAlive_;

    WallComponent() 
        : isAlive_(true)
        {}
};

#endif // SRC_COMPONENTS_WALL_COMPONENT_H
