// ZombieSystem.h
#ifndef ZOMBIESYSTEM_H
#define ZOMBIESYSTEM_H

#include <cstdlib>

#include "../core/System.h"
#include "../core/Entity.h"
#include "../entities/Zombie.h"
#include "../entities/Player.h"

class ZombieSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;

  private:
    bool GetRandomHalfProbability(int);
};

#endif // ZOMBIESYSTEM_H
