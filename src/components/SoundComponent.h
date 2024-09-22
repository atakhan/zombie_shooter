// SoundComponent.h
#ifndef SOUNDCOMPONENT_H
#define SOUNDCOMPONENT_H

class SoundComponent {
public:
    SoundComponent(float, bool);
    
    void SetRadius(float x);
    float GetRadius();
    void SetActive(bool);

private:
    float radius;
    float isActive;
};

#endif // SOUNDCOMPONENT_H
