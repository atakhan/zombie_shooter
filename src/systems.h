#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <iostream>
#include "components.h"
#include "entity.h"
#include <vector>

void MovementSystem(std::vector<Entity>& entities);
void RenderSystem(std::vector<Entity>& entities);
void CollisionSystem(std::vector<Entity>& entities);
void LootSystem(std::vector<Entity>& entities);
void InputSystem(std::vector<Entity>& entities);

#endif // SYSTEMS_H
