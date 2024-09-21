// HealthComponent.cpp
#include "HealthComponent.h"

HealthComponent::HealthComponent(float initialHealth) : health(initialHealth) {}

void HealthComponent::TakeDamage(float damage) {
    health -= damage;
    if (health < 0) health = 0;
}

float HealthComponent::GetHealth() const {
    return health;
}
