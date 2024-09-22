// PositionComponent.cpp
#include "SoundComponent.h"

SoundComponent::SoundComponent(float r, bool a) : radius(r), isActive(a) {}


void SoundComponent::SetRadius(float r) {
    radius = r;
}

float SoundComponent::GetRadius() {
    return radius;
}
void SoundComponent::SetActive(bool a) {
    isActive = a;
}
