#ifndef SRC_COMPONENTS_SCENE_TITLE_COMPONENT_H
#define SRC_COMPONENTS_SCENE_TITLE_COMPONENT_H

#include <raylib-cpp.hpp>

struct SceneTitleComponent {
    std::string title;

    SceneTitleComponent(std::string sceneTitle)
        : title(sceneTitle)
    {}
};

#endif // SRC_COMPONENTS_SCENE_TITLE_COMPONENT_H
