// Player.cpp
#include "Player.h"
#include <iostream>

Player::Player(float posX, float posY, float health, float strength, float agility, float hearingRadius, float attackingRadius)
    : health(health)
    , attack(strength)
    , speed(agility)
    , hearingRadius(hearingRadius)
    , attackingRadius(attackingRadius)
    , currentState(IDLE)
    , position(posX, posY)
    , sound(Config::SOUND_MIN_RADIUS, Config::SOUND_MIN_RADIUS, Config::SOUND_MAX_RADIUS, true)
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
        sound.GetCurrentRadius(), 
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
    return sound.GetCurrentRadius();
}