#include "ManageScenesScene.h"

void ManageScenesScene::Init() {
    Scene::continue_ = true;
    // Scene title
    Scene::AddEntity(SceneTools::CreateScene(Config::GAME_TITLE, Scene::title_));
    
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
    
    
    Scene::AddEntity(UiTools::CreateUIEntity(
        (Vector2){10.0f, 10.0f},
        Config::GAME_TITLE,
        16.0f, 1, 1, 3.0f, RED
    ));
    Scene::AddEntity(UiTools::CreateUIEntity(
        (Vector2){10.0f, 10.0f},
        Scene::title_,
        16.0f, 1, 2, 3.0f, RED
    ));
    
    
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
        if (scene->GetTitle() != "choose a scene") {
            scene->Init();
        }
    }
}

void ManageScenesScene::Update(int *currentSceneIndex) {
    MenuComponent *menu = nullptr;
    for (auto& entity : entities_) {
        if (entity->HasComponent<MenuComponent>()) {
            menu = entity->GetComponent<MenuComponent>();
        }
    }
    if (menu) {
        if (menu->chooseEvent_) {
            if (menu->currentItemIndex_ != *currentSceneIndex && menu->currentItemIndex_ != 0) {
                *currentSceneIndex = menu->currentItemIndex_;
            }
            menu->chooseEvent_ = false;
        } else {
            for (auto& system : systems_) {
                if (system == nullptr) {
                    continue;
                }
                system->Update(&entities_);
            }
        }
        
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
