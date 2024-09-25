// AttackComponent.cpp
#include "AttackComponent.h"

AttackComponent::AttackComponent(float attackStrength, float r) 
    : attackStrength_(attackStrength) 
    , radius_(r) 
{}

float AttackComponent::GetAttackStrength() const {
    return attackStrength_;
}

float AttackComponent::GetRadius() const {
    return radius_;
}
