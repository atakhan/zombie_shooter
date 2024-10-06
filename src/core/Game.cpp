// Game.cpp
#include "Game.h"

void Game::Init() {
    if(!scenes.empty()) {
        scenes[currentSceneIndex]->Init();
    }
}

void Game::Update() {
    int newSceneIndex = currentSceneIndex;
    if (scenes[currentSceneIndex]->Continue()) {
        scenes[currentSceneIndex]->Update(&newSceneIndex);
    } else {
        newSceneIndex = 0;
    }
    if (newSceneIndex != currentSceneIndex) {
        currentSceneIndex = newSceneIndex;
    }
}

void Game::Draw() {
    if (!scenes.empty()) {
        scenes[currentSceneIndex]->Draw();
    }
}

void Game::AddScene(Scene* scene) {
    scene->SetSceneList(&scenes);
    scenes.push_back(scene);
}

bool Game::ShouldExit() {
    return currentMode == Game::Mode::EXIT_GAME;
}

