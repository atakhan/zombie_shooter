#ifndef CIRCLE_CIRCLE_COLLIDER_SYSTEM_H
#define CIRCLE_CIRCLE_COLLIDER_SYSTEM_H

#include <vector>
#include <unordered_set>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class CircleCircleColliderSystem : public System {
  public:
    EventManager& eventManager_;

    CircleCircleColliderSystem(EventManager& eventManager) : eventManager_(eventManager) {}
    
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
    
    bool CollisionDetected(Entity* a, Entity* b);
};

#endif // CIRCLE_CIRCLE_COLLIDER_SYSTEM_H

