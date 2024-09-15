#ifndef SYSTEMS_AI_H
#define SYSTEMS_AI_H

#include <iostream>
#include "../components.h"
#include "../entity.h"
#include <vector>
#include <string>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

class AI {
 public:
  static void NPCRandomMove(std::vector<Entity>& entities) {
    static bool isSeedInitialized = false;
    if (!isSeedInitialized) {
      srand(static_cast<unsigned int>(time(nullptr)));
      isSeedInitialized = true;
    }

    for (auto& entity : entities) {
      // Пропускаем игрока
      // Предполагаем, что ID игрока равен 1
      if (entity.id == 1) { 
        continue;
      }
      
      MovementAI* moveAi = nullptr;
      Velocity* vel = nullptr;
      Power* power = nullptr;

      // Находим компоненты MovementAI, Velocity и Power
      for (auto& comp : entity.components) {
        if (dynamic_cast<MovementAI*>(comp)) {
          moveAi = static_cast<MovementAI*>(comp);
        }
        if (dynamic_cast<Velocity*>(comp)) {
          vel = static_cast<Velocity*>(comp);
        }
        if (dynamic_cast<Power*>(comp)) {
          power = static_cast<Power*>(comp);
        }
      }

      // Логика случайного движения
      if (moveAi && vel && power) {
        // пропускаем entity которые должны быть в покое 
        if (moveAi->isMovement_ == false) {
          continue;
        }

        vel->speedX_ = 0; // Сбрасываем скорость по X
        vel->speedY_ = 0; // Сбрасываем скорость по Y

        // Генерация случайного направления
        int oldDirection = moveAi->direction_;
        int direction = 0;
        if (oldDirection == 0) {
          // Если нет направления, генерируем случайный
          direction = (rand() % 4) + 1; // Значение от 1 до 4
        } else {
          // Если есть направления, то шанс 1 из 100, сгенерировать новый случайным образом
          if ( ((rand() % 100) + 1) == 1 ) { // шанс 1 из 100
            direction = (rand() % 4) + 1; // Значение от 1 до 4
          } else {
            // Случайно генерировать не надо, с оределенным шансом выберем то направление, которое уже есть
            if ( ((rand() % 100) + 1) < 95 ) { // шанс 95%
              direction = oldDirection;
            } else {
              if ( ((rand() % 2) + 1) == 1 ) { // шанс 50 на 50
                if (oldDirection == 1) {
                  direction = 3;
                }
                if (oldDirection == 2) {
                  direction = 4;
                }
                if (oldDirection == 3) {
                  direction = 1;
                }
                if (oldDirection == 4) {
                  direction = 2;
                }
              } else {
                if (oldDirection == 1) {
                  direction = 4;
                }
                if (oldDirection == 2) {
                  direction = 3;
                }
                if (oldDirection == 3) {
                  direction = 2;
                }
                if (oldDirection == 4) {
                  direction = 1;
                }
              }
            }
          }
        }
        moveAi->direction_ = direction;

        switch (moveAi->direction_) {
          case 1: // Движение вверх
            vel->speedY_ = -power->move_;
            break;
          case 2: // Движение вниз
            vel->speedY_ = power->move_;
            break;
          case 3: // Движение влево
            vel->speedX_ = -power->move_;
            break;
          case 4: // Движение вправо
            vel->speedX_ = power->move_;
            break;
        }

        moveAi->isMovement_ = true;
      }
    }
  }
};

#endif // SYSTEMS_AI_H
