#include "TestSystem.h"

void TestSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Test System Initialized" << std::endl;
}

void TestSystem::Draw(std::vector<Entity*> *entities) {
    DrawCircle(
        10.0f,
        10.0f,
        20.0f,
        RED
    );  
}


void TestSystem::Update(std::vector<Entity*> *entities) {
    
}
