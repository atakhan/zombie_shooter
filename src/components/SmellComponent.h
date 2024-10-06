// SoundComponent.h
#ifndef SRC_COMPONENTS_SMELL_COMPONENT_H
#define SRC_COMPONENTS_SMELL_COMPONENT_H

struct SmellComponent {
    float maxRadius;
    float currentRadius;
    float minRadius;
    
    SmellComponent(float currentR, float minR, float maxR)
        : maxRadius(currentR)
        , currentRadius(minR)
        , minRadius(maxR) {}
};

#endif // SRC_COMPONENTS_SMELL_COMPONENT_H
