#ifndef HUMAN_PHYSIOLOGICAL_COMPONENT_H
#define HUMAN_PHYSIOLOGICAL_COMPONENT_H

struct HumanPhysiologicalComponent {
    float air_;
    float water_;
    float food_;
    float heat_;
    float clothes_;
    float sleep_;
    float shelter_;
    float reproduction_;
    
    HumanPhysiologicalComponent(
        float air,
        float water,
        float food,
        float heat,
        float clothes,
        float sleep,
        float shelter,
        float reproduction
    )
        : air_(air)
        , water_(water)
        , food_(food)
        , heat_(heat)
        , clothes_(clothes)
        , sleep_(sleep)
        , shelter_(shelter)
        , reproduction_(reproduction)
    {}
};

#endif // HUMAN_PHYSIOLOGICAL_COMPONENT_H
