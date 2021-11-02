#pragma once

#include "Player.h"
#include "Enemy.h"
#include "StaticEntity.h"
#include "OverworldCamera.h"
#include "Friend.h"

class Area 
{
    private:
        ofImage areaImage;
        ofSoundPlayer areaMusic;
        ofImage areaStage;
        ofPoint entrancePosition;
        std::vector<Enemy*> enemies;
        std::vector<Friend*> friends;
        Area *nextArea;
        string name;
        std::vector<StaticEntity*> staticEntity;
    public:

        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<Friend*> friends, vector<StaticEntity*> staticEntity);
        void resetEnemies();
               ofImage getImage() { return areaImage;};
        ofSoundPlayer getMusic() { return areaMusic;};
        ofImage getStage() { return areaStage;};
        ofPoint getEntrancePos() { return entrancePosition;};
        void setEnemies(std::vector<Enemy*> enemies) { this->enemies = enemies;};
        void setFriends(std::vector<Friend*> friends) { this->friends = friends;};
        vector<Enemy*> getEnemies() { return enemies;};
        vector<Friend*> getFriends() { return friends;};
        int getRemainingEnemies();
        Area* getNextArea() { return nextArea;};
        string getName(){return name;};
        vector<StaticEntity*> getStaticEntity() { return staticEntity;};
};