#ifndef SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
#define SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>
#include <queue>

struct CircleColliderComponent {
    bool isCollide_;
    std::queue<unsigned> collisions_;

    CircleColliderComponent()
        : isCollide_(false)
        , collisions_() 
    {}
};

#endif // SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
