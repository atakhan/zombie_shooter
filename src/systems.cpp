#include "systems.h"

void MovementSystem(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
        Position* pos = nullptr;
        Velocity* vel = nullptr;

        for (auto& comp : entity.components) {
            if (dynamic_cast<Position*>(comp)) pos = static_cast<Position*>(comp);
            if (dynamic_cast<Velocity*>(comp)) vel = static_cast<Velocity*>(comp);
        }

        if (pos && vel) {
            pos->x_ += vel->speedX_;
            pos->y_ += vel->speedY_;
        }
    }
}

void RenderSystem(std::vector<Entity>& entities) {
    for (const auto& entity : entities) {
        Position* pos = nullptr;
        // Sprite* sprite = nullptr;
        Circle* circle = nullptr;

        for (const auto& comp : entity.components) {
            if (dynamic_cast<Position*>(comp)) pos = static_cast<Position*>(comp);
            // if (dynamic_cast<Sprite*>(comp)) sprite = static_cast<Sprite*>(comp);
            if (dynamic_cast<Circle*>(comp)) circle = static_cast<Circle*>(comp);
        }

        if (pos && circle) {
            // DrawTexture(sprite->texture_, pos->x_, pos->y_, WHITE);
            DrawCircle(pos->x_, pos->y_, circle->radius_, circle->color_);
        }
    }
}

void CollisionSystem(std::vector<Entity>& entities) {
    // Логика столкновений между игроком, врагами и лутом
}

void LootSystem(std::vector<Entity>& entities) {
    // Логика сбора лута
}

void InputSystem(std::vector<Entity>& entities) {
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
        if (vel) {
            vel->speedX_ = 0; // Сбрасываем скорость по X
            vel->speedY_ = 0; // Сбрасываем скорость по Y

            if (IsKeyDown(KEY_W)) vel->speedY_ = power->move_ * (-1); // Движение вверх
            if (IsKeyDown(KEY_S)) vel->speedY_ = power->move_;  // Движение вниз
            if (IsKeyDown(KEY_A)) vel->speedX_ = power->move_ * (-1); // Движение влево
            if (IsKeyDown(KEY_D)) vel->speedX_ = power->move_;  // Движение вправо
        }
    }
}

