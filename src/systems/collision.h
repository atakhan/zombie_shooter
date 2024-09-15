#ifndef SYSTEMS_COLLISION_H
#define SYSTEMS_COLLISION_H

#include <iostream>
#include "../components.h"
#include "../entity.h"
#include <vector>
#include <string>

class Collision {
  public:
    static bool CheckCollision(Position *pp, Position *ep, Health *ph, Health *eh) {
        float distance = Vector2Distance(
            (Vector2){pp->x_, pp->y_},
            (Vector2){ep->x_, ep->y_}
        );
        std::cout << distance << " : " << ph->maxHealth_ + eh->maxHealth_ << " = " << ((distance < (ph->maxHealth_ + eh->maxHealth_)) ? "true" : "false") << std::endl;

        return distance < (ph->maxHealth_ + eh->maxHealth_);
    }

    static void Update(std::vector<Entity>& entities) {
        Position* player_pos = nullptr;
        Health* player_health = nullptr;
        for (auto& entity : entities) {
            if (entity.id != 1) { // Предполагаем, что ID игрока равен 1
                continue;
            }
            for (auto& comp : entity.components) {
                if (dynamic_cast<Position*>(comp)) player_pos = static_cast<Position*>(comp);
                if (dynamic_cast<Health*>(comp)) player_health = static_cast<Health*>(comp);
            }
            break;
        }

        if (player_pos && player_health) {
            for (auto& entity : entities) {
                if (entity.id == 1) continue;

                Position* enemy_pos = nullptr;
                Health* enemy_health = nullptr;
                for (auto& comp : entity.components) {
                    if (dynamic_cast<Position*>(comp)) enemy_pos = static_cast<Position*>(comp);
                    if (dynamic_cast<Health*>(comp)) enemy_health = static_cast<Health*>(comp);
                }
                if (enemy_pos && enemy_health) {
                    if (Collision::CheckCollision(player_pos, enemy_pos, player_health, enemy_health) == true) {
                        player_health->currentHealth_ -= 1;
                    }
                }
            }
        }
    }
};

#endif // SYSTEMS_COLLISION_H

