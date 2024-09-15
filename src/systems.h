#ifndef SYSTEMS_H
#define SYSTEMS_H

#include <iostream>
#include "components.h"
#include "entity.h"
#include <vector>
#include <string>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

#include "systems/ai.h"
#include "systems/player_control.h"
#include "systems/movement.h"
#include "systems/collision.h"

void RenderPrototypeSystem(std::vector<Entity>& entities);
void LootSystem(std::vector<Entity>& entities);
void InputSystem(std::vector<Entity>& entities);
void HealthUISystem(std::vector<Entity>& entities);

#endif // SYSTEMS_H
