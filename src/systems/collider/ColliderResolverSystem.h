#ifndef SRC_SYSTEMS_COLLIDER_COLLIDER_RESOLVER_SYSTEM_H
#define SRC_SYSTEMS_COLLIDER_COLLIDER_RESOLVER_SYSTEM_H

#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Entity.h"

class ColliderResolverSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;

    void handleCollision(Entity *A, Entity *B);
};

#endif // SRC_SYSTEMS_COLLIDER_COLLIDER_RESOLVER_SYSTEM_H

