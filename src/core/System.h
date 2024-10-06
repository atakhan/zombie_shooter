// System.h
#ifndef SRC_CORE_SYSTEM_H
#define SRC_CORE_SYSTEM_H

#include <vector>
#include "Entity.h"

class System {
public:
    virtual void Init(std::vector<Entity*> *entities) = 0;
    virtual void Update(std::vector<Entity*> *entities) = 0;
    virtual void Draw(std::vector<Entity*> *entities) = 0;

    virtual ~System() {}
};

#endif // SRC_CORE_SYSTEM_H
