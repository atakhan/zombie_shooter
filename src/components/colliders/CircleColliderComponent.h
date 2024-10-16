#ifndef SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
#define SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>
#include <queue>

struct CircleColliderComponent {
    bool isCollide_;
    float radius_;
    std::queue<unsigned> collisions_;

    CircleColliderComponent(float radius)
        : isCollide_(false)
        , radius_(radius)
        , collisions_() 
    {}
};

#endif // SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
