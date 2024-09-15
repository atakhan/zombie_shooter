#ifndef SYSTEMS_PLAYER_CONTROL_H
#define SYSTEMS_PLAYER_CONTROL_H

#include <iostream>
#include "../components.h"
#include "../entity.h"
#include <vector>
#include <string>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

class PlayerControl {
 public:
  static void handleKeyboardInputs(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
      if (entity.id != 1) { // Предполагаем, что ID игрока равен 1
        continue;
      }
      
      Velocity* vel = nullptr;
      Power* power = nullptr;

      // Находим компонент Velocity и Power
      for (auto& comp : entity.components) {
        if (dynamic_cast<Velocity*>(comp)) {
          vel = static_cast<Velocity*>(comp);
        }
        if (dynamic_cast<Power*>(comp)) {
          power = static_cast<Power*>(comp);
        }
      }

      // Обработка ввода с клавиатуры
      if (vel && power) {
        vel->speedX_ = 0; // Сбрасываем скорость по X
        vel->speedY_ = 0; // Сбрасываем скорость по Y

        if (IsKeyDown(KEY_W)) vel->speedY_ = power->move_ * (-1); // Движение вверх
        if (IsKeyDown(KEY_S)) vel->speedY_ = power->move_;  // Движение вниз
        if (IsKeyDown(KEY_A)) vel->speedX_ = power->move_ * (-1); // Движение влево
        if (IsKeyDown(KEY_D)) vel->speedX_ = power->move_;  // Движение вправо
      }
    }
  }
};

#endif // SYSTEMS_AI_H


SYSTEMS_PLAYER_CONTROL_H