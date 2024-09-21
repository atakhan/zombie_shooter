// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(float health, float strength, float agility, float hearingRadius, float attackingRadius, float posX, float posY)
    : healthComponent(health)
    , attackComponent(strength)
    , speedComponent(agility)
    , hearingRadius(hearingRadius)
    , attackingRadius(attackingRadius)
    , currentState(IDLE)
    , positionComponent(posX, posY) {}


void Player::Update() {
    std::cout << "Player Updating" << std::endl;
}

void Player::TakeDamage(float damage) {
    healthComponent.TakeDamage(damage);
}

void Player::Move() {
    // Логика движения игрока
    std::cout << "Player Moving" << std::endl;
}

void Player::Attack() {
    // Логика выстрела
    std::cout << "Player Shooting (Attacking)" << std::endl;
}

void Player::Draw() {
    DrawCircle(positionComponent.GetPositionX(), positionComponent.GetPositionY(), healthComponent.GetHealth(), GRAY);
}