#include "ManageScenesScene.h"

void ManageScenesScene::Init() {
    std::cout << "ManageScenesScene::Init" << std::endl;
    Scene::continue_ = true;
    // Scene title
    Scene::AddEntity(Tools::CreateScene(
        Config::GAME_TITLE,
        Scene::title_
    ));

    MenuComponent *mainMenu = new MenuComponent(
        1,
        32.0f, 8.0f, 10.0f,
        R6G6B6A8, R0G0B7A8,
        (Vector2){30.0f, 100.0f}
    );

    Scene::AddEntity(Tools::CreateMenu(mainMenu));

    float colNum = 1.0f;
    float rowNum = 1.0f;
    int index = 0;
    for (auto& scene : *scenes_) {
        if (scene == nullptr) { continue; }
        
        MenuItemComponent* menuItem = new MenuItemComponent(
            mainMenu->menuIndex_,
            index,
            scene->GetTitle(),
            colNum,
            rowNum
        );

        BaseUIComponent* baseUi = new BaseUIComponent((Vector2){
            mainMenu->position_.x * colNum,
            mainMenu->position_.y + mainMenu->textSize_ * rowNum
        });
        
        Entity *menuItemEntity = Tools::CreateMenuItem(*baseUi, *menuItem);
        Scene::AddEntity(menuItemEntity);

        rowNum = rowNum + 1.0f;
        index++;
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
        // std::cout << "ManageScenesScene::Update and it is current" << std::endl;
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