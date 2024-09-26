// InputSystem.h
#ifndef LEVEL_GENERATOR_SYSTEM_H
#define LEVEL_GENERATOR_SYSTEM_H

#include "../core/System.h"
#include "../core/Entity.h"
#include "../entities/Player.h"

class LevelGeneratorSystem : public System {
public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
};

#endif // LEVEL_GENERATOR_SYSTEM_H
