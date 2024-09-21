// InputSystem.h
#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "../core/System.h"
#include "../core/Entity.h"

class InputSystem : public System {
public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
    void Draw(std::vector<Entity*> *entities) override;
};

#endif // INPUTSYSTEM_H
