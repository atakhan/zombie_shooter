#include "Player.h"
#include <iostream>

Player::Player(float posX, float posY, float health, float strength, float agility, float hearingRadius, float attackingRadius)
    : health_(health)
    , attack_(strength, attackingRadius)
    , speed_(agility)
    , hearingRadius_(hearingRadius)
    , currentState_(IDLE)
    , position_(posX, posY)
    , sound_(Config::SOUND_MIN_RADIUS, Config::SOUND_MIN_RADIUS, Config::SOUND_MAX_RADIUS, true)
    , camera_()
    {}

void Player::TakeDamage(float damage) {
    health_.TakeDamage(damage);
}

void Player::Attack() {
    // Логика выстрела
    std::cout << "Player Shooting (Attacking)" << std::endl;}

void Player::Draw() {
    DrawCircle(
        position_.GetX(), 
        position_.GetY(), 
        sound_.GetCurrentRadius(), 
        Config::SOUND_RADIUS_COLOR
    );
    DrawCircle(
        position_.GetX(), 
        position_.GetY(), 
        health_.GetHealth(), 
        Config::PLAYER_COLOR
    );
}

float Player::GetRadius() {
    return health_.GetHealth();
}

float Player::GetPositionX() {
    return position_.GetX();
}
float Player::GetPositionY() {
    return position_.GetY();
}

void Player::SetPositionX(float x) {
    position_.SetX(x);
}
void Player::SetPositionY(float y) {
    position_.SetY(y);
}

float Player::GetSoundRadius() {
    return sound_.GetCurrentRadius();
}

Camera2D Player::GetCamera() {
    return camera_.GetCamera();
}

void Player::Idle() {
    DecreaseSoundRadius();
}

void Player::MoveRight() {
    position_.SetX(
        position_.GetX() + speed_.GetSpeed()
    );
    IncreaseSoundRadius();
}

void Player::MoveLeft() {
    position_.SetX(
        position_.GetX() - speed_.GetSpeed()
    );
    IncreaseSoundRadius();
}

void Player::MoveTop() {
    position_.SetY(
        position_.GetY() - speed_.GetSpeed()
    );
    IncreaseSoundRadius();
}

void Player::MoveBottom() {
    position_.SetY(
        position_.GetY() + speed_.GetSpeed()
    );
    IncreaseSoundRadius();
}

void Player::IncreaseSoundRadius() {
    if (sound_.GetCurrentRadius() < sound_.GetMaxRadius()) {
        sound_.SetCurrentRadius(sound_.GetCurrentRadius() + Config::SOUND_RADIUS_STEP);
    }
}

void Player::DecreaseSoundRadius() {
    if (sound_.GetCurrentRadius() > sound_.GetMinRadius()) {
        sound_.SetCurrentRadius(sound_.GetCurrentRadius() - Config::SOUND_RADIUS_STEP);
    }
}
