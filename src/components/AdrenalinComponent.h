// AdrenalinComponent.h
#ifndef ADRENALIN_COMPONENT_H
#define ADRENALIN_COMPONENT_H

struct AdrenalinComponent {
    float current_;
    float step_;
    float min_;
    float max_;

    AdrenalinComponent(float min, float max, float step)
        : current_(min)
        , step_(step)
        , min_(min)
        , max_(max)
        {}
};

#endif // ADRENALIN_COMPONENT_H
