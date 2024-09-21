// Zombie.h
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cmath>
#include <raylib-cpp.hpp>

#include "../core/Entity.h"
#include "../components/HealthComponent.h"
#include "../components/PositionComponent.h"
#include "../components/AttackComponent.h"
#include "../components/SpeedComponent.h"
#include "../components/GoalComponent.h"

class Zombie : public Entity {
public:
    Zombie(float health, float strength, float agility, float hearingRadius, float attackingRadius, float posX, float posY);
    void Update() override;
    void Draw() override;
    void TakeDamage(float damage) override;
    void Move();
    void Attack();
    void Die();
    void SetGoal(float x, float y);

private:
    enum State { IDLE, WALKING, RUNNING, ATTACKING };
    State currentState;

    HealthComponent healthComponent;
    PositionComponent positionComponent;
    GoalComponent goalComponent;
    AttackComponent attackComponent;
    SpeedComponent speedComponent;

    float hearingRadius;
    float attackingRadius;

    void ChangeState(State newState);
    void MoveTo(float speedComponent);
};

#endif // ZOMBIE_H
