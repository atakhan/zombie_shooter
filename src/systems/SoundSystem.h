// InputSystem.h
#ifndef SOUNDSYSTEM_H
#define SOUNDSYSTEM_H

#include "../core/System.h"
#include "../core/Entity.h"
#include "../entities/Player.h"

class SoundSystem : public System {
public:
    void Init(std::vector<Entity*> *entities) override;
    void Update(std::vector<Entity*> *entities) override;
};

#endif // SOUNDSYSTEM_H
