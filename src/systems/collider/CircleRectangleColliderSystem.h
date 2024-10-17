#ifndef SRC_SYSTEMS_COLLIDER_CIRCLE_RECTANGLE_COLLIDER_SYSTEM_H
#define SRC_SYSTEMS_COLLIDER_CIRCLE_RECTANGLE_COLLIDER_SYSTEM_H

#include <vector>
#include <unordered_set>
#include <raylib-cpp.hpp>
#include <iostream>

#include "../../Config.h"
#include "../../core/Bootstrap.h"
#include "../../components/Bootstrap.h"

class CircleRectangleColliderSystem : public System {
  public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
    
    bool CollisionDetected(Entity* circleEntity, Entity* rectangleEntity);
    bool Intersects(float cx, float cy, float cr, float rx, float ry, float rw, float rh);
};

#endif // SRC_SYSTEMS_COLLIDER_CIRCLE_RECTANGLE_COLLIDER_SYSTEM_H