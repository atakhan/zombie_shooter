#ifndef SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
#define SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>

struct CircleColliderComponent {
    Vector2 center_;
    float radius_;

    CircleColliderComponent(Vector2 pos, float r)
        : radius_(r), center_(pos) {}
};

#endif // SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H