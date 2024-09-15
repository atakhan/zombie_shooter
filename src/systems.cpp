#include "systems.h"

void RenderPrototypeSystem(std::vector<Entity>& entities) {
    for (const auto& entity : entities) {
        Position* pos = nullptr;
        Health* health = nullptr;

        for (const auto& comp : entity.components) {
            if (dynamic_cast<Position*>(comp)) pos = static_cast<Position*>(comp);
            if (dynamic_cast<Health*>(comp)) health = static_cast<Health*>(comp);
        }

        if (pos && health) {
            DrawCircle(pos->x_, pos->y_, (health->maxHealth_ / 10), GRAY);
            DrawCircle(pos->x_, pos->y_, (health->currentHealth_ / 10), BLACK);
        }
    }
}

void LootSystem(std::vector<Entity>& entities) {
    // Логика сбора лута
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
