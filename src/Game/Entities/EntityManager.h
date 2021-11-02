#pragma once

#include "Entity.h"
#include "Player.h"
#include "StaticEntity.h"

class EntityManager {
    public:
        ~EntityManager();
        std::vector<Entity*> entities;
        Player *player;

};