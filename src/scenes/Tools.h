#ifndef SRC_SCENES_TOOLS_H
#define SRC_SCENES_TOOLS_H

#include <string>
#include "../core/Bootstrap.h"
#include "../entities/Bootstrap.h" // TODO! not includes

// FIX: bootstrap upper not load a files (not all), bellow is a fix of this problem
#include "../entities/scene/components/SceneComponent.h"
#include "../entities/scene/components/GameTitleComponent.h"
#include "../entities/player/components/Bootstrap.h"
#include "../entities/zombie/components/Bootstrap.h"

class Tools {
  public:
    static Entity* CreateScene(const std::string& gameTitle, const std::string& sceneTitle) {
        Entity *sceneEntity = new Entity();
        sceneEntity->AddComponent<SceneComponent>(SceneComponent(sceneTitle));
        sceneEntity->AddComponent<GameTitleComponent>(GameTitleComponent(gameTitle));

        return sceneEntity;
    }

    static Entity* CreateMap(
        std::vector<std::vector<int>> spawnMap,
        std::vector<std::vector<int>> wallsMap,
        float cellWidth, 
        float cellHeight
    ) {
        Entity *mapEntity = new Entity();
        mapEntity->AddComponent<TerrainComponent>(TerrainComponent(
            spawnMap.at(0).size(), // width
            spawnMap.size(), // height
            cellWidth,
            cellHeight
        ));

        mapEntity->AddComponent<SpawnMapComponent>(SpawnMapComponent(spawnMap));
        mapEntity->AddComponent<WallsMapComponent>(WallsMapComponent(wallsMap));

        return mapEntity;
    }

    static Entity* CreatePlayer(
        Vector2 pos,
        float health,
        float strength, 
        float agility, 
        float attackRadius, 
        float soundRadius
    ) {
        Entity *player = new Entity();
        player->AddComponent<PlayerComponent>(PlayerComponent());
        player->AddComponent<PositionComponent>(PositionComponent(pos));
        player->AddComponent<HealthComponent>(HealthComponent(health));
        player->AddComponent<AttackComponent>(AttackComponent(strength, attackRadius));
        player->AddComponent<SpeedComponent>(SpeedComponent(agility));
        player->AddComponent<SoundComponent>(SoundComponent(soundRadius));
        player->AddComponent<BreathSoundComponent>(BreathSoundComponent(0.5f, 55.0f));
        player->AddComponent<AdrenalinComponent>(AdrenalinComponent(1.0f, 5.0f, 0.005f));
        player->AddComponent<CircleColliderComponent>(CircleColliderComponent(health));
        player->AddComponent<FeetComponent>(FeetComponent());

        CameraComponent camera = CameraComponent();
        player->AddComponent<CameraComponent>(camera);

        Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), camera.camera_);
        player->AddComponent<DirectionComponent>(DirectionComponent(0.0f, worldPos)); // degrees
        
        return player;
    }

    static Vector2 GetPlayerSpawnPositionFromMap(Entity *entity) {
        SpawnMapComponent *spawnMap = entity->GetComponent<SpawnMapComponent>();
        TerrainComponent *terrain = entity->GetComponent<TerrainComponent>();
        if (spawnMap && terrain) {
            for (size_t y = 0; y < terrain->height_; y++) {
                for (size_t x = 0; x < terrain->width_; x++) {
                    // PLAYER SPAWN POINT
                    if (spawnMap->map_[y][x] == 1) {  
                        return (Vector2) {
                            (y * terrain->cellHeight_) + (terrain->cellHeight_ / 2),
                            (x * terrain->cellWidth_) + (terrain->cellWidth_ / 2)
                        };
                    }
                }
            }
        }
        std::cout << "spawn point not found. set custom pos 0,0" << std::endl;
        return (Vector2){0.0f,0.0f};
    }

    static Entity* CreateWall(
        PositionComponent position,
        HealthComponent health,
        RectangleColliderComponent rectCollider
    ) {
        Entity *wall = new Entity();
        wall->AddComponent<WallComponent>(WallComponent());
        wall->AddComponent<PositionComponent>(position);
        wall->AddComponent<HealthComponent>(health);
        wall->AddComponent<RectangleColliderComponent>(rectCollider);

        return wall;
    }

    static Entity* CreateMenu(MenuComponent* menu) {
        Entity *entity = new Entity();
        entity->AddComponent<MenuComponent>(*menu);
        
        return entity;
    }

    static Entity* CreateMenuItem(BaseUIComponent baseUi, MenuItemComponent menuItem) {
        Entity *entity = new Entity();
        entity->AddComponent<MenuItemComponent>(menuItem);
        entity->AddComponent<BaseUIComponent>(baseUi);

        return entity;
    }

    // CREATE ZOMBIES
    static Entity* CreateZombie(
        PositionComponent pos,
        TargetComponent targetPos,
        HealthComponent health
    ) {
        Entity *zombie = new Entity();
        zombie->AddComponent<ZombieComponent>(ZombieComponent());
        zombie->AddComponent<PositionComponent>(pos);
        zombie->AddComponent<TargetComponent>(targetPos);
        zombie->AddComponent<HealthComponent>(health);
        zombie->AddComponent<CircleColliderComponent>(CircleColliderComponent(health.health_));

        return zombie;
    }

    static void DrawMenuItem(BaseUIComponent *baseUi, MenuComponent *menu, MenuItemComponent *menuItem) {
        if (menuItem->menuItemIndex_ == menu->currentItemIndex_) {
            DrawRectangle(
                baseUi->position_.x + menuItem->col_,
                baseUi->position_.y + (menu->textSize_ * menuItem->row_) + menu->lineSpacing_,
                menuItem->text_.length() * 10.0f,
                menu->textSize_,
                menu->selectedColor_
            );
            DrawTextEx(
                GetFontDefault(),
                menuItem->text_.c_str(),
                (Vector2){
                    baseUi->position_.x + menuItem->col_,
                    baseUi->position_.y + (menu->textSize_ * menuItem->row_) + menu->lineSpacing_
                },
                menu->textSize_,
                menu->textSpacing_,
                menu->selectedColor_
            );
        } else {
            DrawTextEx(
                GetFontDefault(),
                menuItem->text_.c_str(),
                (Vector2){
                    baseUi->position_.x + menuItem->col_,
                    baseUi->position_.y + (menu->textSize_ * menuItem->row_) + menu->lineSpacing_
                },
                menu->textSize_,
                menu->textSpacing_,
                menu->color_
            );
        }

    }

    static Entity* CreateUITextEntity(
            Vector2 pos, 
            std::string text,
            float textSize, 
            float colPos, 
            float rowPos, 
            float textSpacing, 
            Color primaryColor,
            Color accentColor
    ) {
        Entity *element = new Entity();
        // element->AddComponent<BaseUIComponent>(BaseUIComponent());
        // element->AddComponent<PositionComponent>(PositionComponent(pos));
        // element->AddComponent<TextComponent>(TextComponent(textSize, textSpacing, 1.0f, primaryColor, accentColor));
        // element->AddComponent<ColPositionComponent>(ColPositionComponent(colPos));
        // element->AddComponent<RowPositionComponent>(RowPositionComponent(rowPos));

        return element;
    }

    static void DrawUITextEntity(Entity *uiElement) {
        // PositionComponent *position = uiElement->GetComponent<PositionComponent>();
        // TextComponent *text = uiElement->GetComponent<TextComponent>();
        // TextSizeComponent *textSize = uiElement->GetComponent<TextSizeComponent>();
        // ColPositionComponent *colNum = uiElement->GetComponent<ColPositionComponent>();
        // RowPositionComponent *rowNum = uiElement->GetComponent<RowPositionComponent>();
        // TextSpacingComponent *textSpacing = uiElement->GetComponent<TextSpacingComponent>();
        // ColorComponent *color = uiElement->GetComponent<ColorComponent>();
        // // PaddingComponent *padding = uiElement->GetComponent<PaddingComponent>();

        // if (position && text && textSize && colNum && rowNum && textSpacing && color) {
        //     DrawTextEx(
        //         GetFontDefault(),
        //         text->text_.c_str(),
        //         (Vector2){
        //             position->position_.x * colNum->value_,
        //             position->position_.y + textSize->value_ * rowNum->value_
        //         },
        //         textSize->value_,
        //         textSpacing->value_,
        //         color->value_
        //     );
        // }
    }
};


#endif  // SRC_SCENES_TOOLS_H