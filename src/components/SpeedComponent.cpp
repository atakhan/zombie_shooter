// SpeedComponent.cpp
#include "SpeedComponent.h"

SpeedComponent::SpeedComponent(float speed) : speed(speed) {}

float SpeedComponent::GetSpeed() const {
    return speed;
}
