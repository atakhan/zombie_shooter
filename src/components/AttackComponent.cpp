// AttackComponent.cpp
#include "AttackComponent.h"

AttackComponent::AttackComponent(float attackStrength) : attackStrength(attackStrength) {}

float AttackComponent::GetAttackStrength() const {
    return attackStrength;
}
