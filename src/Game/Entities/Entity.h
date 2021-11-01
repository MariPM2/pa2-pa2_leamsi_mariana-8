#pragma once
#include "ofMain.h"
enum Direction {left, right, up, down};
class Entity {
    protected:
        // int health;
        // int baseDamage;
        // Fighting coordinates and dimensions
        // int fx, fy, fw, fh;
        // Overworld Coordinates and dimensions
        int ox, oy, ow, oh;
        // ofImage fightingSprite;
        ofImage overworldSprite;
        //int currentHealth = 100;

    public:
        // Entity(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int health, int baseDamage, string fightingPath, string overworldPath);
        Entity(int ox, int oy, int ow, int oh, string overworldPath);
        virtual void tickOverworld() = 0;
        // virtual void tickFighting() = 0;
        virtual void renderOverworld();
        // virtual void renderFighting();
        virtual int getOX() { return ox; };
        virtual int getOY() { return oy; };
        virtual int getOW() { return ow; };
        virtual int getOH() { return oh; };
        virtual ofRectangle getBounds();
        virtual ofRectangle getBounds(int ox, int oy);
        virtual bool collides(Entity* entity);
        virtual void setOX(int ox) { this-> ox = ox; };
        virtual void setOY(int oy) { this-> oy = oy; };
        // int getHealth() { return health; };
        // void setHealth(int health) { this->health = health; };
        // int getDmg() { return baseDamage; };
        // void setDmg(int baseDamage) { this->baseDamage = baseDamage; };

        // int getCurrentHealth(){return currentHealth;};
        // void setCurrentHealth(int currentHealth){this->currentHealth = currentHealth;};
};