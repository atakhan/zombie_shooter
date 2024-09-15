#ifndef SYSTEMS_MOVEMENT_H
#define SYSTEMS_MOVEMENT_H

#include <iostream>
#include "../components.h"
#include "../entity.h"
#include <vector>
#include <string>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

class Movement {
  public:
    static void Update(std::vector<Entity>& entities) {
        for (auto& entity : entities) {
            Position* pos = nullptr;
            Velocity* vel = nullptr;
            Collider* collider = nullptr;

            for (auto& comp : entity.components) {
                if (dynamic_cast<Position*>(comp)) pos = static_cast<Position*>(comp);
                if (dynamic_cast<Velocity*>(comp)) vel = static_cast<Velocity*>(comp);
                if (dynamic_cast<Collider*>(comp)) collider = static_cast<Collider*>(comp);
            }

            if (pos && vel) {
                pos->x_ += vel->speedX_;
                pos->y_ += vel->speedY_;
            }

            if (collider) {
                collider->position_.x = pos->x_;
                collider->position_.y = pos->y_;
            }
        }
    }
};

#endif // SYSTEMS_AI_H


SYSTEMS_MOVEMENT_H