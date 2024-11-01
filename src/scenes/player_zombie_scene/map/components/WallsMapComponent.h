// SpawnMapComponent.h
#ifndef SRC_COMPONENTS_WALLS_MAP_COMPONENT_H
#define SRC_COMPONENTS_WALLS_MAP_COMPONENT_H

#include <vector>

struct WallsMapComponent {
    std::vector<std::vector<int>> map_;
    
    WallsMapComponent(std::vector<std::vector<int>> map)
        : map_(map)
        {}
};

#endif // SRC_COMPONENTS_WALLS_MAP_COMPONENT_H
