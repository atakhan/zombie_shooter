// PositionComponent.cpp
#include "SoundComponent.h"

SoundComponent::SoundComponent(float currentR, float minR, float maxR, bool active) 
    : currentRadius(currentR)
    , minRadius(minR) 
    , maxRadius(maxR) 
    , isActive(active) 
{}


void SoundComponent::SetCurrentRadius(float r) {
    currentRadius = r;
}

void SoundComponent::SetMinRadius(float r) {
    maxRadius = r;
}

void SoundComponent::SetMaxRadius(float r) {
    minRadius = r;
}

float SoundComponent::GetCurrentRadius() {
    return currentRadius;
}

float SoundComponent::GetMinRadius() {
    return minRadius;
}

float SoundComponent::GetMaxRadius() {
    return maxRadius;
}

void SoundComponent::SetActive(bool a) {
    isActive = a;
}
