// Zombie.h
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "../core/Entity.h"
#include "../components/HealthComponent.h"
#include "../components/PositionComponent.h"
#include "../components/AttackComponent.h"
#include "../components/SpeedComponent.h"
#include <iostream>
#include <cmath>

class Zombie : public Entity {
public:
    Zombie(float health, float strength, float agility, float hearingRadius, float attackingRadius);
    void Update(float playerX, float playerY) override;
    void Draw() override;
    void TakeDamage(float damage) override;
    void Move();
    void Attack();
    void Die();

private:
    enum State { IDLE, WALKING, RUNNING, ATTACKING };
    State currentState;

    HealthComponent healthComponent;
    PositionComponent positionComponent;
    AttackComponent attackComponent;
    SpeedComponent speedComponent;

    float hearingRadius;
    float attackingRadius;

    void ChangeState(State newState);
};

#endif // ZOMBIE_H
