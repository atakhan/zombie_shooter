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
#include "../entities/Player.h"

class Zombie : public Entity {
public:
    Zombie(float posX, float posY, float health, float strength, float agility, float hearingRadius, float attackingRadius);
    void Draw() override;
    void TakeDamage(float damage) override;
    void Move();
    void Die();
    void IdleState();
    void RunningState();
    void WalkingState();
    void AttackState();
    void Attack();
    void SetGoal(float x, float y);
    void FindRandomGoal();
    bool HasGoal();
    bool GoalReached();
    PositionComponent *FindFood(std::vector<Entity*> *entities);

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
