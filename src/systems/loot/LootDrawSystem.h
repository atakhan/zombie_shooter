#ifndef LOOT_DRAW_SYSTEM_H
#define LOOT_DRAW_SYSTEM_H

#include <vector>

#include "../../core/System.h"

class LootDrawSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    float GetLootSizeByType(LootComponent::Type type);
};

#endif // LOOT_DRAW_SYSTEM_H
