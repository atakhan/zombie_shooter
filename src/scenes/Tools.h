#ifndef SRC_SCENES_TOOLS_H
#define SRC_SCENES_TOOLS_H

#include <string>
#include <cmath> // For std::fabs

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
            player->AddComponent<LeftFootComponent>(LeftFootComponent(pos));
            player->AddComponent<RightFootComponent>(RightFootComponent(pos));

            CameraComponent camera = CameraComponent();
            player->AddComponent<CameraComponent>(camera);

            Vector2 worldPos = GetScreenToWorld2D(GetMousePosition(), camera.camera_);
            player->AddComponent<DirectionComponent>(DirectionComponent(0.0f, worldPos)); // degrees
            
            return player;
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
            zombie->AddComponent<SoundComponent>(60.0f);
            zombie->AddComponent<CircleColliderComponent>(CircleColliderComponent(health.health_));

            return zombie;
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

      static void DrawMenuItem(BaseUIComponent *baseUi, MenuComponent *menu, MenuItemComponent *menuItem) {
            if (menuItem->menuItemIndex_ == menu->currentItemIndex_) {
                  DrawTextEx(
                        GetFontDefault(),
                        menuItem->text_.c_str(),
                        (Vector2){
                              baseUi->position_.x,
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
                              baseUi->position_.x,
                              baseUi->position_.y + (menu->textSize_ * menuItem->row_) + menu->lineSpacing_
                        },
                        menu->textSize_,
                        menu->textSpacing_,
                        menu->color_
                  );
            }

      }

      static bool CompareFloats(float a, float b, float epsilon) {
            return std::fabs(a - b) < epsilon;
      }
      };


#endif  // SRC_SCENES_TOOLS_H