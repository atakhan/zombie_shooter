#ifndef SRC_COMPONENTS_TERRAIN_COMPONENT_H
#define SRC_COMPONENTS_TERRAIN_COMPONENT_H

#include <raylib-cpp.hpp>

struct TerrainComponent {
    float width_;
    float height_;
    float cellHeight_;
    float cellWidth_;

    TerrainComponent(float w, float h, float cw, float ch) 
        : width_(w)
        , height_(h) 
        , cellWidth_(cw) 
        , cellHeight_(ch) 
        {}
};

#endif // SRC_COMPONENTS_TERRAIN_COMPONENT_H
