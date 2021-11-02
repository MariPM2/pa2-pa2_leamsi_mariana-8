#pragma once

#include "State.h"
#include "Area.h"
#include "Player.h"
#include "Enemy.h"
#include "OverworldCamera.h"
#include "PauseState.h"
#include "BattleState.h"
#include "Friend.h"
#include "Boss.h"

class OverworldState : public State
{
    private:
        ofImage overworldImage;
        Player *player;
        OverworldCamera *camera;
        Area *area;
        std::vector<Enemy*> enemies;
        Enemy *enemy;
<<<<<<< HEAD
        PauseState *pauseState;
        StaticEntity *staticEntity;
        std::vector<StaticEntity*> staticEntities;
=======
>>>>>>> 968422c0dd9b2a84e38f157f92725f8824726e48
        
    public:
        OverworldState(Player *player, Area *area);
        Player* getPlayer() { return player;};
        void setEnemy(Enemy *enemy) { this->enemy = enemy;};
        Enemy* getEnemy() { return enemy;};
        void loadArea(Area *Area);
        Area* getArea() { return area;};
        void tick();
        void render();
        void keyPressed(int key);
        void keyReleased(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        PauseState *pauseState;
        int enemigo=0;
    };