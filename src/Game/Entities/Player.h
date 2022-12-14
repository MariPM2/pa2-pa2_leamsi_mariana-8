#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Fighting.h"
#include "StaticEntity.h"
#include "Friend.h"

#define INIT_X 100
#define INIT_Y 100
#define CENTER_X 288
#define CENTER_Y 208

#define OXDIMENSION 2688
#define OYDIMENSION 2560


class Player : public Fighting {
    private:
        Direction direction = Direction::up;
        int speed = 8;
        bool walking = false;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        // Animation *fighting;
        vector<char> pressedKeys;
        vector<StaticEntity*> ent;
        vector<Friend*> f;
    
    public:
        Player(int health, int baseDamage);
        ~Player();
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        int currHealth;
        void setEnt(vector<StaticEntity*> ent){ this->ent=ent;};
        void sefF(vector<Friend*> f){ this->f=f;};
};