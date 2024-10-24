// FeetComponent.h
#ifndef FEET_COMPONENT_H
#define FEET_COMPONENT_H

#include <raylib.hpp>

struct FeetComponent {
    Rectangle left_;
    Rectangle right_;
    Vector2 leftOrigin_;
    Vector2 rightOrigin_;
    
    FeetComponent(Rectangle left, Rectangle right, Vector2 leftOrigin, Vector2 rightOrigin)
        : left_(left)
        , right_(right)
        , leftOrigin_(leftOrigin)
        , rightOrigin_(rightOrigin)
        {};
};

#endif // FEET_COMPONENT_H
