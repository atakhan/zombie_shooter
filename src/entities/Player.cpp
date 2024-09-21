// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(float health, float strength, float agility, float hearingRadius, float attackingRadius, float posX, float posY)
    : health(health)
    , attack(strength)
    , speed(agility)
    , hearingRadius(hearingRadius)
    , attackingRadius(attackingRadius)
    , currentState(IDLE)
    , position(posX, posY) {}

void Player::TakeDamage(float damage) {
    health.TakeDamage(damage);
}

void Player::Attack() {
    // Логика выстрела
    std::cout << "Player Shooting (Attacking)" << std::endl;
}

void Player::Draw() {
    DrawCircle(
        position.GetPositionX(), 
        position.GetPositionY(), 
        health.GetHealth(), 
        BLUE
    );
}

float Player::GetPositionX() {
    return position.GetPositionX();
}
float Player::GetPositionY() {
    return position.GetPositionY();
}

void Player::SetPositionX(float x) {
    position.SetPositionX(x);
}
void Player::SetPositionY(float y) {
    position.SetPositionY(y);
}
