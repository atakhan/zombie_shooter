#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <vector>

#include "../core/System.h"
#include "../core/Entity.h"
#include "../components/Bootstrap.h"

class CollisionSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;

    bool CheckCircleCollision(const CircleColliderComponent &a, const CircleColliderComponent &b);
};

#endif // COLLISION_SYSTEM_H
