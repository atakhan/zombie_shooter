#ifndef SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
#define SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>

struct CircleColliderComponent {
    float radius;          // Radius of the circle
    bool isTrigger;        // Whether the collider triggers events without causing physical collisions

    CircleColliderComponent(float r, bool trigger = false)
        : radius(r), isTrigger(trigger) {}
};

#endif // SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
