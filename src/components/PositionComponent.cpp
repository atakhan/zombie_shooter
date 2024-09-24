// PositionComponent.cpp
#include "PositionComponent.h"

PositionComponent::PositionComponent(float x, float y) : posX(x), posY(y) {}

void PositionComponent::SetPosition(float x, float y) {
    posX = x;
    posY = y;
}
void PositionComponent::SetX(float x) {
    posX = x;
}
void PositionComponent::SetY(float y) {
    posY = y;
}

float PositionComponent::GetX() {
    return posX;
}

float PositionComponent::GetY() {
    return posY;
}
