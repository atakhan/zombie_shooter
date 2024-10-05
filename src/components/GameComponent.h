#ifndef GAME_COMPONENT_H
#define GAME_COMPONENT_H

#include <raylib-cpp.hpp>

struct GameComponent {
    std::string title;
    std::string currentSceneTitle;

    GameComponent(std::string gameTitle, std::string sceneTitle)
        : title(gameTitle)
        , currentSceneTitle(sceneTitle)
    {}
};

#endif // GAME_COMPONENT_H
