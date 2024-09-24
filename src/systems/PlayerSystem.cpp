// PlayerSystem.cpp
#include "PlayerSystem.h"
#include <iostream>

void PlayerSystem::Init(std::vector<Entity*> *entities) {
    std::cout << "Input System Initialized" << std::endl;
}

void PlayerSystem::Update(std::vector<Entity*> *entities) {
    for (const auto& entity : *entities) {
        Player* player = nullptr;
        if (dynamic_cast<Player*>(entity)) player = static_cast<Player*>(entity);
        if (player) {
            if (IsKeyDown(KEY_RIGHT)) {
                if (IsKeyDown(KEY_LEFT)) {
                    player->Idle();
                } else {
                    if (IsKeyDown(KEY_UP)) {
                        player->MoveRight();
                        player->MoveTop();
                    } else
                    if (IsKeyDown(KEY_DOWN)) {
                        player->MoveRight();
                        player->MoveBottom();
                    } else {
                        player->MoveRight();
                    }
                }
            } else
            if (IsKeyDown(KEY_LEFT)) {
                if (IsKeyDown(KEY_RIGHT)) {
                    player->Idle();
                } else {
                    if (IsKeyDown(KEY_UP)) {
                        player->MoveLeft();
                        player->MoveTop();
                    } else
                    if (IsKeyDown(KEY_DOWN)) {
                        player->MoveLeft();
                        player->MoveBottom();
                    } else {
                        player->MoveLeft();
                    }
                }
            } else
            if (IsKeyDown(KEY_UP)) {
                if (IsKeyDown(KEY_DOWN)) {
                    player->Idle();
                } else {
                    if (IsKeyDown(KEY_RIGHT)) {
                        player->MoveTop();
                        player->MoveRight();
                    } else
                    if (IsKeyDown(KEY_LEFT)) {
                        player->MoveTop();
                        player->MoveLeft();
                    } else {
                        player->MoveTop();
                    }
                }
            } else
            if (IsKeyDown(KEY_DOWN)) {
                if (IsKeyDown(KEY_UP)) {
                    player->Idle();
                } else {
                    if (IsKeyDown(KEY_RIGHT)) {
                        player->MoveBottom();
                        player->MoveRight();
                    } else
                    if (IsKeyDown(KEY_LEFT)) {
                        player->MoveBottom();
                        player->MoveLeft();
                    } else {
                        player->MoveBottom();
                    }
                }
            } else {
                player->Idle();
            }
        }
    }
}

