#ifndef CIRCLE_COLLIDER_COMPONENT_H
#define CIRCLE_COLLIDER_COMPONENT_H

#include <raylib-cpp.hpp>

class CircleColliderComponent {
public:
    float radius_;
    Vector2 position_;

    CircleColliderComponent(Vector2 pos, float radius);
    float GetAttackStrength() const;
    float GetRadius() const;
};

#endif // CIRCLE_COLLIDER_COMPONENT_H
