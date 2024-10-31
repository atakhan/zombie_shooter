// FeetComponent.h
#ifndef FEET_COMPONENT_H
#define FEET_COMPONENT_H

#include <raylib.hpp>

struct FeetComponent {
    Rectangle left_;
    Rectangle right_;
    Vector2 leftOrigin_;
    Vector2 rightOrigin_;
    
    FeetComponent()
        : left_({0.0f, 0.0f, 0.0f, 0.0f})
        , right_({0.0f, 0.0f, 0.0f, 0.0f})
        , leftOrigin_({ 0.0f, 0.0f })
        , rightOrigin_({ 0.0f, 0.0f })
        {};
};

#endif // FEET_COMPONENT_H
