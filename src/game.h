#ifndef GAME_H
#define GAME_H

#include <raylib-cpp.hpp>
#include "entity.h"
#include "components.h"
#include "systems.h"
#include <vector>

class Game {
public:
    void Init();
    void Update();
    void Draw();
private:
    std::vector<Entity> entities;
    void LoadResources();
    void CreatePlayer();
    void CreateEnemies();
    void CreateLoot();
};

#endif // GAME_H