// System.h
#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "../Config.h"
#include "../components/Bootstrap.h"
#include "Entity.h"

class System {
public:
    virtual void Init(std::vector<Entity*> *entities) = 0;
    virtual void Update(std::vector<Entity*> *entities) = 0;
    virtual void Draw(std::vector<Entity*> *entities) = 0;

    virtual ~System() {}
};

#endif // SYSTEM_H
