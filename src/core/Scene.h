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
    int index_;
    bool continue_;
    std::string title_;
    std::vector<Scene*> *scenes_;
    float width_;
    float height_;

    std::vector<System*> systems_;
    std::vector<Entity*> entities_;
    
    Scene(int index, bool isContinue, float width, float height, std::string title = "no title") 
        : title_(title)
        , index_(index)
        , continue_(isContinue)
        , width_(width)
        , height_(height)
    {}

    virtual void Init() = 0;
    virtual void Update(int *currentSceneIndex) = 0;
    virtual void Draw() = 0;
    
    void SetSceneList(std::vector<Scene*> *scenes);

    void AddSystem(System* system);
    void RemoveSystem(System* system);
    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);
    bool Continue() { return continue_;};
    void HandleExit(int *currentSceneIndex);
    std::string GetTitle();
};

#endif // SCENE_H
