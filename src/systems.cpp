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

void HealthUISystem(std::vector<Entity>& entities) {
    for (auto& entity : entities) {
        if (entity.id != 1) { // Предполагаем, что ID игрока равен 1
            continue;
        }
        
        Health* health = nullptr;
        for (auto& comp : entity.components) {
            if (dynamic_cast<Health*>(comp)) {
                health = static_cast<Health*>(comp);
                break;
            }
        }
        if (health) {
            std::string text = std::to_string(health->currentHealth_);
            DrawText(text.c_str(), 10, 10, 32, DARKGREEN);
        }
    }
}

void AIMovementSystem(std::vector<Entity>& entities) {
    static bool isSeedInitialized = false;
    if (!isSeedInitialized) {
        srand(static_cast<unsigned int>(time(nullptr)));
        isSeedInitialized = true;
    }

    for (auto& entity : entities) {
        if (entity.id == 1) { // Предполагаем, что ID игрока равен 1
            continue;
        }
        
        MovementAI* moveAi = nullptr;
        Velocity* vel = nullptr;
        Power* power = nullptr;

        // Находим компонент Velocity и Power
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

        if (moveAi && vel && power) {
            vel->speedX_ = 0; // Сбрасываем скорость по X
            vel->speedY_ = 0; // Сбрасываем скорость по Y

            // Генерация случайного направления
            moveAi->direction_ = (rand() % 4) + 1; // Значение от 1 до 4

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