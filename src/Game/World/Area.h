#pragma once

#include "Player.h"
#include "Enemy.h"
#include "OverworldCamera.h"
#include "Friend.h"
#include "StaticEntity.h"

class Area 
{
    private:
        ofImage areaImage;
        ofSoundPlayer areaMusic;
        ofImage areaStage;
        ofPoint entrancePosition;
        std::vector<Enemy*> enemies;
        std::vector<Friend*> friends;
        std::vector<StaticEntity*> staticEntities;
        Area *nextArea;
        string name;

    public:
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<Friend*> friends, vector<StaticEntity*> staticEntities);
        void resetEnemies();
        ofImage getImage() { return areaImage;};
        ofSoundPlayer getMusic() { return areaMusic;};
        ofImage getStage() { return areaStage;};
        ofPoint getEntrancePos() { return entrancePosition;};
        void setEnemies(std::vector<Enemy*> enemies) { this->enemies = enemies;};
        void setFriends(std::vector<Friend*> friends) { this->friends = friends;};
        void setStaticEntites(std::vector<StaticEntity*> staticEntities) { this->staticEntities = staticEntities;};
        vector<Enemy*> getEnemies() { return enemies;};
        vector<Friend*> getFriends() { return friends;};
        vector<StaticEntity*> getStaticEntities() { return staticEntities;};
        int getRemainingEnemies();
        Area* getNextArea() { return nextArea;};
        string getName(){return name;};
        bool BossIsDead=false;
        
};