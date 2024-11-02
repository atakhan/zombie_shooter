// Game.h
#ifndef SRC_CORE_GAME_H
#define SRC_CORE_GAME_H

#include <vector>
#include "Scene.h"

class Game {
public:
    std::vector<Scene*> scenes;
    enum class Mode {
        CHOOSE_SCENE = 0,
        PLAY_SCENE,
        EXIT_GAME,
    };
    Mode currentMode_;
    int currentSceneIndex_;
    
    Game(Mode mode) : currentMode_(mode), currentSceneIndex_(0) {}

    void Init();
    void Update();
    void Draw();    
    
    void AddScene(Scene* scene);
    bool ShouldExit();
};

#endif // SRC_CORE_GAME_H