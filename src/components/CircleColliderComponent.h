#ifndef SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
#define SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>

struct CircleColliderComponent {
    float radius;          // Radius of the circle
    Vector2 position;      // Position of the circle collider relative to the entity
    bool isTrigger;        // Whether the collider triggers events without causing physical collisions

    CircleColliderComponent(float r, Vector2 pos, bool trigger = false)
        : radius(r), position(pos), isTrigger(trigger) {}
};

#endif // SRC_COMPONENTS_CIRCLE_COLLIDER_COMPONENT_H
