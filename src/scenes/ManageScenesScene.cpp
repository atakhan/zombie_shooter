#include "ManageScenesScene.h"

void ManageScenesScene::Init() {
    Scene::continue_ = true;
    // Scene title
    Scene::AddEntity(SceneTools::CreateScene(
        Config::GAME_TITLE,
        Scene::title_
    ));
    
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

    // Init systems
    for (auto& system : systems_) {
        if (system == nullptr) {
            continue;
        }
        system->Init(&entities_);
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
        }
        HandleExit(currentSceneIndex);
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
