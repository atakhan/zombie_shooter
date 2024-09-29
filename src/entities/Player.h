// // Player.h
// #ifndef PLAYER_H
// #define PLAYER_H

// #include <iostream>
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
// #include "../components/CameraComponent.h"

// class Player : public Entity {
//   public:
//     enum State { IDLE, WALKING, RUNNING, ATTACKING };
//     State currentState_;
//     HealthComponent health_;
//     PositionComponent position_;
//     AttackComponent attack_;
//     SpeedComponent speed_;
//     SoundComponent sound_;
//     CameraComponent camera_;
//     float hearingRadius_;
    
//     Player(float posX, float posY, float health, float strength, float agility, float hearingRadius, float attackingRadius);
//     void Draw() override;
//     void TakeDamage(float damage);
//     void Attack();
//     float GetPositionX();
//     float GetPositionY();
//     void SetPositionX(float);
//     void SetPositionY(float);
//     float GetRadius();
//     float GetSoundRadius();
//     Camera2D GetCamera();
//     void IncreaseSoundRadius();
//     void DecreaseSoundRadius();
//     void Idle();
//     void MoveRight();
//     void MoveLeft();
//     void MoveTop();
//     void MoveBottom();    
// };

// #endif // PLAYER_H
