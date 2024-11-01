// SpawnMapComponent.h
#ifndef SRC_COMPONENTS_SPAWN_MAP_COMPONENT_H
#define SRC_COMPONENTS_SPAWN_MAP_COMPONENT_H

#include <vector>

struct SpawnMapComponent {
    std::vector<std::vector<int>> map_;
    
    SpawnMapComponent(std::vector<std::vector<int>> spawnMap)
        : map_(spawnMap)
        {}
};

#endif // SRC_COMPONENTS_SPAWN_MAP_COMPONENT_H
