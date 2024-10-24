// System.h
#ifndef SRC_CORE_SYSTEM_H
#define SRC_CORE_SYSTEM_H

#include <vector>
#include "Entity.h"

class System {
public:
    bool debug_;
    virtual void Init(std::vector<Entity*> *entities) = 0;
    virtual void Update(std::vector<Entity*> *entities) = 0;
    virtual void Draw(std::vector<Entity*> *entities) = 0;

    template <typename T>
    static Entity *GetEntityByComponent(std::vector<Entity*> *entities) {
        Entity *player = nullptr;
        for (auto& entity : *entities) {
            if (entity->HasComponent<T>()) {
                player = entity;
                break;
            }
        }
        return player;
    }

    virtual ~System() {}
};

#endif // SRC_CORE_SYSTEM_H
