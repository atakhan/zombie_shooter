#include "ManageScenesScene.h"

void ManageScenesScene::Init() {
    Scene::continue_ = true;
    // Scene title
    SceneTools::CreateScene(Config::GAME_TITLE, Scene::title_, this);
    
    Entity *menu = MenuTools::CreateMenu(
        Vector2{30.0f, 100.0f}, 
        Config::DEFAULT_FONT_SIZE, 
        Config::DEFAULT_TEXT_SPACING, 
        Config::DEFAULT_LINE_SPACING,
        Config::DEFAULT_FONT_COLOR
    );
    Scene::AddEntity(menu);

    float colNum = 1.0f;
    float rowNum = 1.0f;
    int index = 0;
    for (auto& scene : *scenes_) {
        if (scene == nullptr) {
            continue;
        }
        Entity *menuItem = MenuTools::CreateMenuItem(
            index,
            menu,
            scene->GetTitle(),
            colNum,
            rowNum
        );
        if (menuItem) {
            Scene::AddEntity(menuItem);
            rowNum = rowNum + 1.0f;
            index++;
        }
    }
    
    Scene::AddSystem(new MenuControlSystem());
    Scene::AddSystem(new MenuDrawSystem());

    // Update Systems

    // Init systems
    for (auto& system : systems_) {
        if (system == nullptr) {
            continue;
        }
        system->Init(&entities_);
    }

    // Init scenes
    for (auto& scene : *scenes_) {
        if (scene == nullptr) {
            continue;
        }
        // // init all scenes except current
        // if (scene->index_ != index_) {
        //     scene->Init();
        // }
    }
}

void ManageScenesScene::Update(int *currentSceneIndex) {
    if (*currentSceneIndex == index_) {
        MenuComponent *menu = nullptr;
        for (auto& entity : entities_) {
            if (entity->HasComponent<MenuComponent>()) {
                menu = entity->GetComponent<MenuComponent>();
            }
        }
        if (menu) {
            if (menu->chooseEvent_) {
                std::cout << "CHOOSE EVENT!!!!" << std::endl;
                std::cout << "menu item index: " << std::to_string(menu->currentItemIndex_) << std::endl;
                std::cout << "current scene index: " << std::to_string(*currentSceneIndex) << std::endl;
                if (menu->currentItemIndex_ != *currentSceneIndex) {
                    menu->chooseEvent_ = false;
                    *currentSceneIndex = menu->currentItemIndex_;
                    scenes_->at(*currentSceneIndex)->continue_ = true;
                } else {
                    menu->chooseEvent_ = false;
                    continue_ = true;
                }
            } else {
                for (auto& system : systems_) {
                    if (system == nullptr) {
                        continue;
                    }
                    system->Update(&entities_);
                }
            }
        } else {
            std::cout << "ManageScenesScene::Update MenuComponent NOT FOUND in scene: " << std::to_string(*currentSceneIndex) << std::endl;
        }
        HandleExit(currentSceneIndex);
    } else {
        std::cout 
            << "ManageScenesScene::Update CONTINUE STOPED: *currentSceneIndex != index_  -  " 
            << std::to_string(*currentSceneIndex) 
            << std::to_string(index_) 
            << std::endl;
    }
}

void ManageScenesScene::Draw() {
    for (auto& system : systems_) {
        if (system == nullptr) {
            continue;
        }
        system->Draw(&entities_);
    }
}
