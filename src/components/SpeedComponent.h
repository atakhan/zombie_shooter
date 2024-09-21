// SpeedComponent.h
#ifndef SPEEDCOMPONENT_H
#define SPEEDCOMPONENT_H

class SpeedComponent {
public:
    SpeedComponent(float speed);
    float GetSpeed() const;

private:
    float speed;
};

#endif // SPEEDCOMPONENT_H
