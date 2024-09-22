// Zombie.h
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <vector>
#include <cstdlib>
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

class Zombie : public Entity {
public:
    Zombie(float health, float strength, float agility, float hearingRadius, float attackingRadius, float posX, float posY);
    void Draw() override;
    void TakeDamage(float damage) override;
    void Idle();
    void Move();
    void Attack();
    void Die();
    void SetGoal(float x, float y);
    void FindGoal();
    bool HasGoal();
    bool GoalReached();
    PositionComponent *FindEat(std::vector<Entity*> *entities);

private:
    enum State { IDLE, WALKING, RUNNING, ATTACKING };
    State currentState_;

    HealthComponent health_;
    PositionComponent position_;
    GoalComponent goal_;
    AttackComponent attack_;
    SpeedComponent speed_;
    SoundComponent sound_;

    float hearingRadius_;
    float attackingRadius_;

    void ChangeState(State newState);
    void MoveTo(float speedComponent);
};

#endif // ZOMBIE_H
