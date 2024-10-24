// DirectionComponent.h
#ifndef DIRECTION_COMPONENT_H
#define DIRECTION_COMPONENT_H

#include <raylib.hpp>

struct DirectionComponent {
    float rotation_;
    Vector2 mousePos_;
    bool isMove_;

    DirectionComponent(float rotationDegrees, Vector2 mousePos)
        : rotation_(rotationDegrees)
        , mousePos_(mousePos)
        , isMove_(false)
        {};
};

#endif // DIRECTION_COMPONENT_H

// DrawRectanglePro()