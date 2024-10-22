// FeetComponent.h
#ifndef FEET_COMPONENT_H
#define FEET_COMPONENT_H

#include <raylib.hpp>

struct FeetComponent {
    Vector2 leftPosition_;
    Vector2 rightPosition_;
    float leftRadius_;
    float rightRadius_;

    FeetComponent(Vector2 leftPosition, Vector2 rightPosition, float leftRadius, float rightRadius)
        : leftPosition_(leftPosition)
        , rightPosition_(rightPosition)
        , leftRadius_(leftRadius)
        , rightRadius_(rightRadius)
        {};
};

#endif // FEET_COMPONENT_H
