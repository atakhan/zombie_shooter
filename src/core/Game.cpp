// Game.cpp
#include "Game.h"

void Game::Init() {
    currentSceneIndex = 0;
    for (auto& scene : scenes) {
        if (scene == nullptr) {
            std::cerr << "scene pointer is null!" << std::endl;
            continue;
        }
        scene->Init();
    }
}

void Game::Update() {
    if (currentMode == Mode::CHOOSE_SCENE) {
        std::cout << "Choose Scene mode" << std::endl;
        scenes[0]->Update();
    } else 
    if (currentMode == Mode::PLAY_SCENE) {
        std::cout << "Play Scene mode" << std::endl;
        if (!scenes.empty()) {
            if (scenes[currentSceneIndex]->Continue()) {
                scenes[currentSceneIndex]->Update();
            } else {
                ExitScene();
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
    scenes.push_back(scene);
}

void Game::ExitScene() {
    currentSceneIndex = 0;
    currentMode = Mode::CHOOSE_SCENE;
}
