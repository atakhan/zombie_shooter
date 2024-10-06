#ifndef SRC_COMPONENTS_SCENE_TITLE_COMPONENT_H
#define SRC_COMPONENTS_SCENE_TITLE_COMPONENT_H

#include <raylib-cpp.hpp>

struct SceneComponent {
    std::string title;
    int index_;

    SceneComponent(std::string sceneTitle)
        : title(sceneTitle)
        , index_()
    {}
};

#endif // SRC_COMPONENTS_SCENE_TITLE_COMPONENT_H
