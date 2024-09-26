#include "Player.h"
#include <iostream>

Player::Player(float posX, float posY, float health, float strength, float agility, float hearingRadius, float attackingRadius)
    : health(health)
    , attack(strength, attackingRadius)
    , speed(agility)
    , hearingRadius(hearingRadius)
    , currentState(IDLE)
    , position(posX, posY)
    , sound(Config::SOUND_MIN_RADIUS, Config::SOUND_MIN_RADIUS, Config::SOUND_MAX_RADIUS, true)
    {}

void Player::TakeDamage(float damage) {
    health.TakeDamage(damage);
}

void Player::Attack() {
    // Логика выстрела
    std::cout << "Player Shooting (Attacking)" << std::endl;}

void Player::Draw() {
    DrawCircle(
        position.GetX(), 
        position.GetY(), 
        sound.GetCurrentRadius(), 
        Config::SOUND_RADIUS_COLOR
    );
    DrawCircle(
        position.GetX(), 
        position.GetY(), 
        health.GetHealth(), 
        Config::PLAYER_COLOR
    );
}

float Player::GetRadius() {
    return health.GetHealth();
}

float Player::GetPositionX() {
    return position.GetX();
}
float Player::GetPositionY() {
    return position.GetY();
}

void Player::SetPositionX(float x) {
    position.SetX(x);
}
void Player::SetPositionY(float y) {
    position.SetY(y);
}

float Player::GetSoundRadius() {
    return sound.GetCurrentRadius();
}

void Player::Idle() {
    DecreaseSoundRadius();
}

void Player::MoveRight() {
    position.SetX(
        position.GetX() + speed.GetSpeed()
    );
    IncreaseSoundRadius();
}

void Player::MoveLeft() {
    position.SetX(
        position.GetX() - speed.GetSpeed()
    );
    IncreaseSoundRadius();
}

void Player::MoveTop() {
    position.SetY(
        position.GetY() - speed.GetSpeed()
    );
    IncreaseSoundRadius();
}

void Player::MoveBottom() {
    position.SetY(
        position.GetY() + speed.GetSpeed()
    );
    IncreaseSoundRadius();
}

void Player::IncreaseSoundRadius() {
    if (sound.GetCurrentRadius() < sound.GetMaxRadius()) {
        sound.SetCurrentRadius(sound.GetCurrentRadius() + Config::SOUND_RADIUS_STEP);
    }
}

void Player::DecreaseSoundRadius() {
    if (sound.GetCurrentRadius() > sound.GetMinRadius()) {
        sound.SetCurrentRadius(sound.GetCurrentRadius() - Config::SOUND_RADIUS_STEP);
    }
}

