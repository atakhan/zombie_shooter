// PositionComponent.h
#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

class PositionComponent {
public:
    PositionComponent(float x, float y);
    void SetPosition(float x, float y);
    void SetPositionX(float x);
    void SetPositionY(float y);
    float GetPositionX();
    float GetPositionY();

private:
    float posX;
    float posY;
};

#endif // POSITIONCOMPONENT_H
