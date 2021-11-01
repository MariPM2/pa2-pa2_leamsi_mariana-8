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
<<<<<<< HEAD
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<StaticEntity*> staticEntity, vector<Friend*> friends);
=======
        Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<StaticEntity*> staticEntity, vector<Friend*> friends);
>>>>>>> 3d2dc8963e0ec57fdcf130d38541749e51c9e512
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