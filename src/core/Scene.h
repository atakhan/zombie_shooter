// Scene.h
#ifndef SCENE_H
#define SCENE_H

#include <raylib-cpp.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

#include "../Config.h"
#include "System.h"
#include "Entity.h"

class Scene {
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    void AddSystem(System* system);
    void RemoveSystem(System* system);
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    bool Continue() { return continue_;};

protected:
    bool continue_;
    std::vector<System*> systems_;
    std::vector<Entity*> entities_;
};

#endif // SCENE_H
