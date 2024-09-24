// PositionComponent.cpp
#include "GoalComponent.h"

GoalComponent::GoalComponent(float x, float y) : posX(x), posY(y) {}

void GoalComponent::SetPosition(float x, float y) {
    posX = x;
    posY = y;
}

float GoalComponent::GetX() {
    return posX;
}

float GoalComponent::GetY() {
    return posY;
}

bool GoalComponent::Reached(float currentPosX, float currentPosY) {
    const float epsilon = 1.0f; // Define a small threshold for comparison

    // Check if the current position is within epsilon of the target position
    if (std::abs(currentPosX - posX) < epsilon && std::abs(currentPosY - posY) < epsilon) {
        return true;
    }
    return false;
}

bool GoalComponent::IsActive() {
    return active;
}

void GoalComponent::SetActive(bool v) {
    active = v;
}