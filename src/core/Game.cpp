// Game.cpp
#include "Game.h"

void Game::Init() {
    currentSceneIndex = 0;
    // Инициализация текущей сцены
    if (!scenes.empty()) {
        scenes[currentSceneIndex]->Init();
    }
}

void Game::Update() {
    if (!scenes.empty()) {
        scenes[currentSceneIndex]->Update();
    }
}

void Game::Draw() {
    if (!scenes.empty()) {
        scenes[currentSceneIndex]->Draw();
    }
}

void Game::AddScene(Scene* scene) {
    scenes.push_back(scene);
}
