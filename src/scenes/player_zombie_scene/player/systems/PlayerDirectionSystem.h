#ifndef PLAYER_DIRECTION_SYSTEM_H
#define PLAYER_DIRECTION_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>
#include <algorithm>

#include "../../../../Config.h"
#include "../../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"


class PlayerDirectionSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    float AngleBetweenVectors(const Vector2& mousePos, const Vector2& playerPos);
};

#endif // PLAYER_DIRECTION_SYSTEM_H
