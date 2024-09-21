// GoalComponent.h
#ifndef GOALCOMPONENT_H
#define GOALCOMPONENT_H

#include <cmath>

class GoalComponent {
public:
    GoalComponent(float x, float y);
    void SetPosition(float x, float y);
    float GetPositionX();
    float GetPositionY();
    bool Reached(float x, float y);

private:
    float posX;
    float posY;
};

#endif // GOALCOMPONENT_H
