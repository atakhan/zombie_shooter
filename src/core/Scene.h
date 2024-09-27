// Scene.h
#ifndef SCENE_H
#define SCENE_H

#include <raylib-cpp.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
#include "System.h"
#include "../Config.h"
#include "Entity.h"
#include "../entities/Player.h"

class Scene {
public:
    void Init();
    void Update();
    void Draw();
    
    void AddCamera(Camera2D* camera);
    void InitCamera();
    void UpdateCamera();

    void AddSystem(System* system);
    void RemoveSystem(System* system);
    void UpdateSystems();

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);

    void DrawEntities();

protected:
    Camera2D *camera_;
    std::vector<System*> systems_;
    std::vector<Entity*> entities_;
};

#endif // SCENE_H
