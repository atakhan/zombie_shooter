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
        if (newSceneIndex != currentSceneIndex) {
            currentSceneIndex = newSceneIndex;
            currentMode = Mode::PLAY_SCENE;
        }
    } else {
        if (currentSceneIndex == 0) {
            currentMode = Mode::EXIT_GAME;
        } else 
        if (currentSceneIndex > 0) {
            currentMode = Mode::CHOOSE_SCENE;
        }
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

