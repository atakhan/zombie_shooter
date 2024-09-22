// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(float health, float strength, float agility, float hearingRadius, float attackingRadius, float posX, float posY, float soundR)
    : health(health)
    , attack(strength)
    , speed(agility)
    , hearingRadius(hearingRadius)
    , attackingRadius(attackingRadius)
    , currentState(IDLE)
    , position(posX, posY)
    , sound(soundR, true)
    {}

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
        sound.GetRadius(), 
        Config::SOUND_RADIUS_COLOR
    );
    DrawCircle(
        position.GetPositionX(), 
        position.GetPositionY(), 
        health.GetHealth(), 
        Config::PLAYER_COLOR
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

float Player::GetSoundRadius() {
    return sound.GetRadius();
}