#pragma once

#include "Entity.h"
#include "Animation.h"
#include "Enemy.h"
#include "State.h"

class Boss : public Enemy{
    private:
        Direction direction = Direction::down;
        int speed = 8;
        bool walking = false;
        int renderX = 1000;
        int renderY = 1000;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        string id;
        int moveTimer;
        bool dead = false;
        string entityName;
        ofImage sprite; 
    
    public:
        Boss(string id, int health, int basedamage, string entityName, int ox, int oy, string fightingPath, string overworld);
        ~Boss();
        
        bool PhasePass=false;
        void phase();
        bool getHasPhase(){return PhasePass;};
};
    
