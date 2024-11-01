#ifndef SRC_SYSTEMS_COLLIDER_COLLIDER_RESOLVER_SYSTEM_H
#define SRC_SYSTEMS_COLLIDER_COLLIDER_RESOLVER_SYSTEM_H

#include <raylib-cpp.hpp>
#include <iostream>
#include <cmath>

#include "../../../Config.h"
#include "../../../core/Bootstrap.h"
#include "../components/Bootstrap.h"

class ColliderResolverSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void HandleCollision(Entity *a, Entity *b);
    void PlayerToZombie(Entity *a, Entity *b);
    void PlayerToWall(Entity *a, Entity *b);
    void ZombieToZombie(Entity *a, Entity *b);
    void CircleToRectangle(Entity *a, Entity *b);
    void CircleToCircle(Entity *a, Entity *b);
};

#endif // SRC_SYSTEMS_COLLIDER_COLLIDER_RESOLVER_SYSTEM_H

