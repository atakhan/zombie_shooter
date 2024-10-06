// Game.cpp
#include "Game.h"

void Game::Init() {
    if(!scenes.empty()) {
        scenes[currentSceneIndex]->Init();
    }
}

void Game::Update() {
    if (currentMode == Mode::CHOOSE_SCENE) {
        if (scenes[0]->Continue()) {
            scenes[0]->Update();
        } else {
            // Exit game
            currentSceneIndex = 0;
            currentMode = Mode::EXIT_GAME;
        }
    } else 
    if (currentMode == Mode::PLAY_SCENE) {
        if (!scenes.empty()) {
            if (scenes[currentSceneIndex]->Continue()) {
                scenes[currentSceneIndex]->Update();
            } else {
                // Exit scene
                scenes[currentSceneIndex]->Exit();
                currentSceneIndex = 0;
                currentMode = Mode::CHOOSE_SCENE;
            }
        }
    }
}

void Game::Draw() {
    if (currentMode == Mode::CHOOSE_SCENE) {
        scenes[0]->Draw();
    } else 
    if (currentMode == Mode::PLAY_SCENE) {
        if (!scenes.empty()) {
            scenes[currentSceneIndex]->Draw();
        }
    }
}

void Game::AddScene(Scene* scene) {
    scene->SetSceneList(&scenes);
    scenes.push_back(scene);
}

bool Game::ShouldExit() {
    return currentMode == Game::Mode::EXIT_GAME;
}

