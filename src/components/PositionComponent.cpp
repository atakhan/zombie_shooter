// PositionComponent.cpp
#include "PositionComponent.h"

PositionComponent::PositionComponent(float x, float y) : posX(x), posY(y) {}

void PositionComponent::SetPosition(float x, float y) {
    posX = x;
    posY = y;
}
void PositionComponent::SetPositionX(float x) {
    posX = x;
}
void PositionComponent::SetPositionY(float y) {
    posY = y;
}

float PositionComponent::GetPositionX() {
    return posX;
}

float PositionComponent::GetPositionY() {
    return posY;
}
