// Game.cpp
#include "Game.h"

void Game::Init() {
    if(!scenes.empty()) {
        for (auto &scene : scenes) {
            scene->Init();
        }
    }
}

void Game::Update() {
    int newSceneIndex = currentSceneIndex_;
    scenes.at(currentSceneIndex_)->Update(&newSceneIndex);
    if (newSceneIndex != currentSceneIndex_) {
        currentSceneIndex_ = newSceneIndex;
        scenes.at(currentSceneIndex_)->continue_ = true;
    }
}

void Game::Draw() {
    if (!scenes.empty()) {
        scenes[currentSceneIndex_]->Draw();
    }
}

void Game::AddScene(Scene* scene) {
    scene->SetSceneList(&scenes);
    scenes.push_back(scene);
}

bool Game::ShouldExit() {
    return currentMode_ == Game::Mode::EXIT_GAME;
}

