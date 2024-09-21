// Scene.h
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "System.h"
#include "Entity.h"

class Scene {
public:
    virtual void Init();
    virtual void Update();
    virtual void Draw();
    
    void AddSystem(System* system) {systems.push_back(system);}
    void RemoveSystem(System* system);
    void UpdateSystems();
    
    void AddEntity(Entity* entity) {entities.push_back(entity);}
    void RemoveEntity(Entity* entity);
    void UpdateEntities(float playerX, float playerY);
    
    void DrawEntities();
protected:
    std::vector<System*> systems;
    std::vector<Entity*> entities;
};

#endif // SCENE_H
