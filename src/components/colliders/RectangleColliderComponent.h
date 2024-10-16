#ifndef SRC_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H
#define SRC_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>

struct RectangleColliderComponent {
    bool isCollide_;
    float width_;
    float height_;
    std::queue<unsigned> collisions_;

    RectangleColliderComponent(float w, float h)
        : width_(w)
        , height_(h)
        , isCollide_(false)
        , collisions_()
        {}
};

#endif // SRC_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H
