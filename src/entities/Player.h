// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <raylib-cpp.hpp>

#include "../core/Config.h"
#include "../core/Entity.h"
#include "../components/HealthComponent.h"
#include "../components/PositionComponent.h"
#include "../components/AttackComponent.h"
#include "../components/SpeedComponent.h"
#include "../components/GoalComponent.h"
#include "../components/SoundComponent.h"

class Player : public Entity {
public:
    Player(float health, float strength, float agility, float hearingRadius, float attackingRadius, float posX, float posY, float soundR);
    void Draw() override;
    void TakeDamage(float damage) override;
    void Attack();
    float GetPositionX();
    float GetPositionY();
    void SetPositionX(float);
    void SetPositionY(float);
    float GetSoundRadius();

private:
    enum State { IDLE, WALKING, RUNNING, ATTACKING };
    State currentState;

    HealthComponent health;
    PositionComponent position;
    AttackComponent attack;
    SpeedComponent speed;
    SoundComponent sound;

    float hearingRadius;
    float attackingRadius;
};

#endif // PLAYER_H