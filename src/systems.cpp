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
