#ifndef SYSTEMS_BOOTSTRAP_H
#define SYSTEMS_BOOTSTRAP_H

// Player systems
#include "./player/PlayerDrawSystem.h"
#include "./player/PlayerControlSystem.h"

// Zombie systems
#include "./zombie/ZombieDrawSystem.h"
#include "./zombie/ZombieMoveSystem.h"
#include "./zombie/ZombieTargetingSystem.h"

// Human systems
#include "./human/HumanDrawSystem.h"
#include "./human/HumanMoveSystem.h"
#include "./human/HumanTargetingSystem.h"
#include "./human/HumanStaminaSystem.h"

// Loot systems
#include "./loot/LootDrawSystem.h"

// Scene systems
#include "./scene/SceneControlSystem.h"

// Menu systems
#include "./menu/MenuControlSystem.h"
#include "./menu/MenuDrawSystem.h"

// UI draw systems
#include "./ui/UIDrawSystem.h"

#endif // SYSTEMS_BOOTSTRAP_H
