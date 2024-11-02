#ifndef SRC_ENTITIES_SCENE_COMPONENTS_SCENE_COMPONENT_H
#define SRC_ENTITIES_SCENE_COMPONENTS_SCENE_COMPONENT_H

#include <raylib-cpp.hpp>

struct SceneComponent {
    std::string title;
    int index_;

    SceneComponent(std::string sceneTitle)
        : title(sceneTitle)
        , index_()
    {}
};

#endif // SRC_ENTITIES_SCENE_COMPONENTS_SCENE_COMPONENT_H
