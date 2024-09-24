// PositionComponent.h
#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

class PositionComponent {
public:
    PositionComponent(float x, float y);
    void SetPosition(float x, float y);
    void SetX(float x);
    void SetY(float y);
    float GetX();
    float GetY();

private:
    float posX;
    float posY;
};

#endif // POSITIONCOMPONENT_H
