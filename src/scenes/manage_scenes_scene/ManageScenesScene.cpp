#include "ManageScenesScene.h"

void ManageScenesScene::Init() {
    Scene::continue_ = true;
    // Scene title
    Scene::AddEntity(CreateScene(
        Config::GAME_TITLE,
        Scene::title_
    ));
    
    MenuComponent* menu = new MenuComponent(
        20.0f, 2.0f, 10.0f,
        R6G6B6A8, R0G0B7A8,
        (Vector2){30.0f, 100.0f}
    );
    Entity *menuEntity = CreateMenu(menu);
    Scene::AddEntity(menuEntity);

    float colNum = 1.0f;
    float rowNum = 1.0f;
    int index = 0;
    for (auto& scene : *scenes_) {
        if (scene == nullptr) { continue; }
        MenuItemComponent* menuItem = new MenuItemComponent(
            index,
            scene->GetTitle(),
            colNum,
            rowNum
        );
        Entity *menuItemEntity = CreateMenuItem(menu, menuItem);
        if (menuItem) {
            Scene::AddEntity(menuItemEntity);
            rowNum = rowNum + 1.0f;
            index++;
        }
    }
    
    Scene::AddSystem(new MenuControlSystem());

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


Entity* ManageScenesScene::CreateScene(const std::string& gameTitle, const std::string& sceneTitle) {
    Entity *sceneEntity = new Entity();
    sceneEntity->AddComponent<SceneComponent>(SceneComponent(sceneTitle));
    sceneEntity->AddComponent<GameTitleComponent>(GameTitleComponent(gameTitle));
    return sceneEntity;
}

Entity* ManageScenesScene::CreateMenu(MenuComponent* menu) {
    Entity *entity = new Entity();
    entity->AddComponent<MenuComponent>(*menu);
    
    return entity;
}

Entity* ManageScenesScene::CreateMenuItem(MenuComponent *menu, MenuItemComponent *menuItem) {
    Entity *entity = new Entity();
    entity->AddComponent<MenuItemComponent>(
        MenuItemComponent(*menuItem)
    );

    return entity;
}