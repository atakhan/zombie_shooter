// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <raylib-cpp.hpp>

#include "../Config.h"
#include "../core/Entity.h"
#include "../components/HealthComponent.h"
#include "../components/PositionComponent.h"
#include "../components/AttackComponent.h"
#include "../components/SpeedComponent.h"
#include "../components/GoalComponent.h"
#include "../components/SoundComponent.h"

class Player : public Entity {
public:
    Player(float posX, float posY, float health, float strength, float agility, float hearingRadius, float attackingRadius);
    void Draw() override;
    void TakeDamage(float damage) override;
    void Attack();
    float GetPositionX();
    float GetPositionY();
    void SetPositionX(float);
    void SetPositionY(float);
    float GetRadius();
    float GetSoundRadius();
    void IncreaseSoundRadius();
    void DecreaseSoundRadius();
    void Idle();
    void MoveRight();
    void MoveLeft();
    void MoveTop();
    void MoveBottom();

private:
    enum State { IDLE, WALKING, RUNNING, ATTACKING };
    State currentState;

    HealthComponent health;
    PositionComponent position;
    AttackComponent attack;
    SpeedComponent speed;
    SoundComponent sound;

    float hearingRadius;
};

#endif // PLAYER_H
