// InputSystem.h
#ifndef PLAYERSYSTEM_H
#define PLAYERSYSTEM_H

#include "../core/System.h"
#include "../core/Entity.h"
#include "../entities/Player.h"

class PlayerSystem : public System {
public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
};

#endif // PLAYERSYSTEM_H
