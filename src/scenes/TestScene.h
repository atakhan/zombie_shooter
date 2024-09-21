// Scene.h
#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include <vector>
#include "../core/Scene.h"
#include "../entities/Zombie.h"

class TestScene : public Scene {
public:
    void Init() override;
    void Update() override;
    void Draw() override;
protected:
    std::vector<System*> systems;
    std::vector<Entity*> entities;
};

#endif // TEST_SCENE_H
