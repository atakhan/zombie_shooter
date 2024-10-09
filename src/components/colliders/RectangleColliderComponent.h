#ifndef SRC_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H
#define SRC_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>

struct RectangleColliderComponent {
    Vector2 center_;
    float radius_;

    RectangleColliderComponent(Vector2 pos, float r)
        : radius_(r), center_(pos) {}
};

#endif // SRC_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H
