// System.h
#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "Entity.h"

class System {
public:
    virtual void Init(std::vector<Entity*> *entities) = 0;
    virtual void Update(std::vector<Entity*> *entities) = 0;
    virtual void Draw(std::vector<Entity*> *entities) = 0;
};

#endif // SYSTEM_H
