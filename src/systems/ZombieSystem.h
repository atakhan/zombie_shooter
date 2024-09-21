// ZombieSystem.h
#ifndef ZOMBIESYSTEM_H
#define ZOMBIESYSTEM_H

#include "../core/System.h"
#include "../core/Entity.h"
#include "../entities/Zombie.h"

class ZombieSystem : public System {
public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // ZOMBIESYSTEM_H
