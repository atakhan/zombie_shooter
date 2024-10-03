// SoundComponent.h
#ifndef SMELL_COMPONENT_H
#define SMELL_COMPONENT_H

struct SmellComponent {
    float maxRadius;
    float currentRadius;
    float minRadius;
    
    SmellComponent(float currentR, float minR, float maxR)
        : maxRadius(currentR)
        , currentRadius(minR)
        , minRadius(maxR) {}
};

#endif // SMELL_COMPONENT_H
