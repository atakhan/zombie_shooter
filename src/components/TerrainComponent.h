#ifndef SRC_COMPONENTS_TERRAIN_COMPONENT_H
#define SRC_COMPONENTS_TERRAIN_COMPONENT_H

#include <raylib-cpp.hpp>

struct TerrainComponent {
    float width_;
    float height_;

    TerrainComponent(float w, float h) : width_(w), height_(h) {}
};

#endif // SRC_COMPONENTS_TERRAIN_COMPONENT_H
