// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    virtual void Update(float playerX, float playerY) = 0;
    virtual void Draw() = 0;
    virtual void TakeDamage(float damage) = 0;
    virtual ~Entity() {}
};

#endif // ENTITY_H
