// Scene.h
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "System.h"
#include "Entity.h"

class Scene {
public:
    void Init();
    void Update();
    void Draw();
    
    void AddSystem(System* system);
    void RemoveSystem(System* system);

    void AddEntity(Entity* entity);
    void RemoveEntity(Entity* entity);

    void UpdateSystems();
    void DrawEntities();
protected:
    std::vector<System*> systems;
    std::vector<Entity*> entities;
};

#endif // SCENE_H
