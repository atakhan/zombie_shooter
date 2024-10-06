#ifndef SRC_UTILS_SCENE_TOOLS_H
#define SRC_UTILS_SCENE_TOOLS_H

#include <string>
#include "../Config.h"
#include "../core/Bootstrap.h"
#include "../components/Bootstrap.h"
#include "../systems/Bootstrap.h"

class SceneTools {  
  public:
    // CREATE GAME
    static Entity* CreateScene(const std::string& gameTitle, const std::string& sceneTitle) {
        Entity *game = new Entity();
        game->AddComponent<GameTitleComponent>(GameTitleComponent(gameTitle));
        game->AddComponent<SceneTitleComponent>(SceneTitleComponent(sceneTitle));
        return game;
    }

    // CREATE PLAYER
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
        player->AddComponent<CameraComponent>(CameraComponent());
        
        return player;
    }

};

#endif // SRC_UTILS_SCENE_TOOLS_H