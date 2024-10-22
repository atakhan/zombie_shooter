#ifndef SYSTEMS_BOOTSTRAP_H
#define SYSTEMS_BOOTSTRAP_H

// Player systems
#include "./player/PlayerAdrenalinSystem.h"
#include "./player/PlayerBreathSystem.h"
#include "./player/PlayerCameraSystem.h"
#include "./player/PlayerControlSystem.h"
#include "./player/PlayerDrawSystem.h"
#include "./player/PlayerFeetMoveSystem.h"

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


// Map systems
#include "./map/TerrainDrawSystem.h"

// Collider systems
#include "./collider/CircleCircleColliderSystem.h"
#include "./collider/CircleRectangleColliderSystem.h"
#include "./collider/ColliderResolverSystem.h"

// Debug systems
#include "./debug/DebugUIDrawSystem.h"
#include "./debug/PlayerStatsDrawSystem.h"
#include "./debug/SoundDrawSystem.h"
#include "./debug/TargetDrawSystem.h"
#include "./debug/ZombieStatsDrawSystem.h"

// UI draw systems
#include "./ui/UIDrawSystem.h"

#endif // SYSTEMS_BOOTSTRAP_H
