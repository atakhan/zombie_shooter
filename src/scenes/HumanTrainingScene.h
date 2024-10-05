#ifndef HUMAN_TRAINING_SCENE
#define HUMAN_TRAINING_SCENE

#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"

class HumanTrainingScene : public Scene {
    void Init() override;
    void Update() override;
    void Draw() override;

    void SpawnPlayer();
    void CreateHumanWithDefaultComponents(Entity *human);
    void SpawnHuman();
    void SpawnHumanInPos(float posX, float posY);
    void SpawnHumanInPosWithStatus(float posX, float posY, HumanComponent::Status status);
    void SpawnHumanInPosWithStatusAndTarget(float posX, float posY, HumanComponent::Status status, float tarX, float tarY);
    void SpawnLoot();
    void SpawnZombie();
};

#endif // HUMAN_TRAINING_SCENE