#ifndef ADRENALIN_SYSTEM_H
#define ADRENALIN_SYSTEM_H

#include <vector>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../../../Config.h"
#include "../../../../core/Bootstrap.h"
#include "../../player/components/Bootstrap.h"


class PlayerAdrenalinSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void DecreaseAdrenaline(AdrenalinComponent *playerAdrenalin);
    void IncreaseAdrenaline(AdrenalinComponent *playerAdrenalin);
};

#endif // ADRENALIN_SYSTEM_H
