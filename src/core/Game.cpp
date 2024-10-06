// Game.cpp
#include "Game.h"

void Game::Init() {
    if(!scenes.empty()) {
        for (auto &scene : scenes) {
            if (scenes.at(scene->index_)->Continue() == true) {
                scenes[scene->index_]->Init();
            }
        }
    }
}

void Game::Update() {
    int newSceneIndex = currentSceneIndex;

    // Count active scenes
    Scene *scene = nullptr;
    int activeScenesNumber = scenes.size();
    for (auto &scene : scenes) {
        if (scenes.at(scene->index_)->Continue() == false) {
            activeScenesNumber--;
        }
    }
    // if no active scenes then exit game
    if (activeScenesNumber == 0) {
        std::cout << "No active scenes. go exit!" << std::endl;
        currentMode = Game::Mode::EXIT_GAME;
    } else {
        if (scenes.at(currentSceneIndex)->Continue()) {
            scenes.at(currentSceneIndex)->Update(&newSceneIndex);
            if (newSceneIndex != currentSceneIndex) {
                currentSceneIndex = newSceneIndex;
            }
        } else {
            newSceneIndex = 0;
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

