// PositionComponent.h
#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include <raylib-cpp.hpp>

struct PositionComponent {
    Vector2 position_;

    PositionComponent(float x, float y) : position_((Vector2){x, y}) {}
    PositionComponent(Vector2 pos) : position_(pos) {}
};

#endif // POSITION_COMPONENT_H
