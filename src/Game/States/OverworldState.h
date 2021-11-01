#pragma once

#include "State.h"
#include "Area.h"
#include "Player.h"
#include "Enemy.h"
#include "OverworldCamera.h"
#include "PauseState.h"
#include "BattleState.h"
#include "StaticEntity.h"

class OverworldState : public State
{
    private:
        ofImage overworldImage;
        Player *player;
        OverworldCamera *camera;
        Area *area;
        std::vector<Enemy*> enemies;
        Enemy *enemy;
        PauseState *pauseState;
        StaticEntity *staticEntity;
        std::vector<StaticEntity*> staticEntity;
        
    public:
        OverworldState(Player *player, Area *area);
        Player* getPlayer() { return player;};
        void setEnemy(Enemy *enemy) { this->enemy = enemy;};
        void setStaticEntity (StaticEntity *staticEntity) { this->staticEntity = staticEntity; }
        Enemy* getEnemy() { return enemy;};
        StaticEntity* getStaticEntity() { return staticEntity;};
        void loadArea(Area *Area);
        Area* getArea() { return area;};
        void tick();
        void render();
        void keyPressed(int key);
        void keyReleased(int key);
        void mousePressed(int x, int y, int button);
        void reset();
    };