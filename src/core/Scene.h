// Scene.h
#ifndef SCENE_H
#define SCENE_H

#include <raylib-cpp.hpp>
#include <algorithm>
#include <iostream>
#include <vector>

#include "System.h"
#include "Entity.h"

class Scene {
public:
    std::string title_;
    
    Scene(std::string title = "no title")
        : title_(title)
        {}

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    
    void SetSceneList(std::vector<Scene*> *scenes);

    void AddSystem(System* system);
    void RemoveSystem(System* system);
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    bool Continue() { return continue_;};
    void Exit();
    std::string GetTitle();

protected:
    bool continue_;
    std::vector<Scene*> *scenes_;

    std::vector<System*> systems_;
    std::vector<Entity*> entities_;
};

#endif // SCENE_H
