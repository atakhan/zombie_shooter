#include "TestScene.h"

void TestScene::Init() {
    this->AddEntity(new Zombie(10.0f, 2.0f, 3.0, 30.0f));
}