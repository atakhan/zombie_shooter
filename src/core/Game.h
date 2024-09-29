// Game.h
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Scene.h"

class Game {
public:
    void Init();
    void Update();
    void Draw();
    void AddScene(Scene* scene);
    
private:
    std::vector<Scene*> scenes;
    int currentSceneIndex;
};

#endif // GAME_H