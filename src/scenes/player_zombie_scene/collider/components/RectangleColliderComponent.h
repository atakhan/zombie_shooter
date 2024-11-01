#ifndef SRC_SCENES_PLAYER_ZOMBIE_SCENE_COLLIDER_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H
#define SRC_SCENES_PLAYER_ZOMBIE_SCENE_COLLIDER_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H

#include <queue>
#include <raylib-cpp.hpp>

struct RectangleColliderComponent {
    bool isCollide_;
    float width_;
    float height_;
    std::queue<unsigned> collisions_;

    RectangleColliderComponent(float w, float h)
        : width_(w)
        , height_(h)
        , isCollide_(false)
        , collisions_()
        {}
};

#endif // SRC_SCENES_PLAYER_ZOMBIE_SCENE_COLLIDER_COMPONENTS_RECTANGLE_COLLIDER_COMPONENT_H
