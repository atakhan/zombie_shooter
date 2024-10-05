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
    };
    
    Game(Mode mode) : currentMode(mode) {}

    void Init();
    void Update();
    void Draw();
    void AddScene(Scene* scene);
    void ExitScene();
    void ChangeMode(Mode mode);
    
private:
    std::vector<Scene*> scenes;
    int currentSceneIndex;
    Mode currentMode;
};

#endif // GAME_H