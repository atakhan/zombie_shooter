#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "components.h"

struct Entity {
    int id;
    std::vector<Component*> components; // Используем void* для универсальности
};

#endif // ENTITY_H
