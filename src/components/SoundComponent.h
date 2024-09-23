// SoundComponent.h
#ifndef SOUNDCOMPONENT_H
#define SOUNDCOMPONENT_H

class SoundComponent {
public:
    SoundComponent(float currentR, float minR, float maxR, bool active);
    
    void SetCurrentRadius(float x);
    void SetMinRadius(float x);
    void SetMaxRadius(float x);
    float GetCurrentRadius();
    float GetMinRadius();
    float GetMaxRadius();
    void SetActive(bool);

private:
    float maxRadius;
    float currentRadius;
    float minRadius;
    float isActive;
};

#endif // SOUNDCOMPONENT_H
