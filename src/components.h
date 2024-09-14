#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <raylib-cpp.hpp>

class Component {
public:
    virtual ~Component() {} // Virtual destructor for proper cleanup
};

struct Position : public Component {
    float x_, y_;
    Position(float x, float y) : x_(x), y_(y) {};
};

struct Velocity : public Component {
    float speedX_, speedY_;
    Velocity(float sx, float sy) : speedX_(sx), speedY_(sy) {};
};

struct Power : public Component {
    float move_;
    Power(float m) : move_(m) {};
};

struct Health : public Component {
    int currentHealth_;
    int maxHealth_;
    Health(int ch, int mh) : currentHealth_(ch), maxHealth_(mh) {};
};

struct Sprite : public Component {
    Texture2D texture_;
    Sprite(Texture2D t) : texture_(t) {}
};

struct Circle : public Component {
    int centerX_;
    int centerY_;
    float radius_;
    Color color_;
    Circle(int centerX, int centerY, float radius, Color color) 
        : centerX_(centerX)
        , centerY_(centerY)
        , radius_(radius)
        , color_(color) {};
};

struct Loot : public Component {
    int value_;
    Loot(int v) : value_(v) {};
};

struct Enemy : public Component {
    bool isAggressive_;
    Enemy(bool v) : isAggressive_(v) {};
};

struct MovementAI : public Component {
    bool isMovement_;
    int direction_;
    MovementAI(bool isM, int d) : isMovement_(isM), direction_(d) {};
};

#endif // COMPONENTS_H
