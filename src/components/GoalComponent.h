// GoalComponent.h
#ifndef GOALCOMPONENT_H
#define GOALCOMPONENT_H

#include <cmath>

class GoalComponent {
public:
    GoalComponent(float x, float y);
    void SetPosition(float x, float y);
    float GetX();
    float GetY();
    bool Reached(float x, float y);
    bool IsActive();
    void SetActive(bool);

private:
    float posX;
    float posY;
    bool active;
};

#endif // GOALCOMPONENT_H
