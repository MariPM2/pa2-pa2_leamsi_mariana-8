#pragma once

#include "Entity.h" 
#include "Animation.h"
#include "Fighting.h"

class Friend : public Entity {
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
        string entityName;
        ofImage sprite; 
    
    public:
        Friend(string id, string entityName, int ox, int oy, int ow, int oh);
        // ~Enemy();
        int getOX() { return ox; };
        int getOY() { return oy; };
        void setRenderX(int x){ renderX = x; };
        void setRenderY(int y){ renderY = y; };
        void tickOverworld();
        void tickFighting();
        void renderOverworld();
        void keyPressed(int key);
        void keyReleased(int key);
        void reset();
        string getId(){ return id; };
        ofImage getSprite() { return overworldSprite;};
        ofRectangle getBounds();
        ofRectangle getBounds(int ox,int oy);
        bool talking=false;
};