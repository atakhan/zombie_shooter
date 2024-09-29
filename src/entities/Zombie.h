// // Zombie.h
// #ifndef ZOMBIE_H
// #define ZOMBIE_H

// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <cmath>
// #include <raylib-cpp.hpp>

// #include "../Config.h"
// #include "../core/Entity.h"
// #include "../components/HealthComponent.h"
// #include "../components/PositionComponent.h"
// #include "../components/AttackComponent.h"
// #include "../components/SpeedComponent.h"
// #include "../components/GoalComponent.h"
// #include "../components/SoundComponent.h"
// #include "../components/CircleColliderComponent.h"
// #include "../entities/Player.h"

// class Zombie : public Entity {
// public:
//     enum State { IDLE, WALKING, RUNNING, ATTACKING };
//     State currentState_;
//     HealthComponent health_;
//     PositionComponent position_;
//     GoalComponent goal_;
//     AttackComponent attack_;
//     SpeedComponent speed_;
//     SoundComponent sound_;
//     CircleColliderComponent collider_;
//     float hearingRadius_;

//     Zombie(float posX, float posY, float health, float strength, float agility, float hearingRadius, float attackingRadius);
//     void Draw() override;
    
//     // Fighting
//     void TakeDamage(float damage);
//     float Attack();
//     bool CanAttack(Player *player);
    
//     // Movings
//     void Walk();
//     void Run();
//     void Move();
    
//     // Goals
//     void SetGoal(float x, float y);
//     void FindRandomGoal();
//     bool HasGoal();
//     void MoveToGoal(float speedComponent);
//     bool GoalReached();
//     PositionComponent *FindFood(std::vector<Entity*> *entities);
    
//     // States
//     void IdleState();
//     void RunningState();
//     void WalkingState();
//     void AttackState();
//     void Die();
//     void ChangeState(State newState);
// };

// #endif // ZOMBIE_H
