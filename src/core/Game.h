// Game.h
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Scene.h"

class Game {
public:
    enum class Mode {
        PLAY_SCENE,
        CHOOSE_SCENE,
        EXIT_GAME,
    };
    Mode currentMode;
    
    Game(Mode mode) : currentMode(mode), currentSceneIndex(0) {}

    void Init();
    void Update();
    void Draw();    
    
    void AddScene(Scene* scene);
    bool ShouldExit();
    
private:
    std::vector<Scene*> scenes;
    int currentSceneIndex;
};

#endif // GAME_H