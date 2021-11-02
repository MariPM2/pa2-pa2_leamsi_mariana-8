#include "Area.h"

<<<<<<< HEAD

Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<Friend*> friends, vector<StaticEntity*> staticEntity)

=======
Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<Friend*> friends)
>>>>>>> 968422c0dd9b2a84e38f157f92725f8824726e48
{
    this->nextArea = nextArea;
    areaImage.load(areaImagePath);
    areaMusic.load(areaMusicPath);
    areaStage.load(areaStagePath);
    this->entrancePosition = entrancePosition;
    this->enemies = enemies;
    this->name = name;
<<<<<<< HEAD
    this->staticEntity = staticEntity;
    this->friends = friends;
=======
    this->friends=friends;
>>>>>>> 968422c0dd9b2a84e38f157f92725f8824726e48
}

void Area::resetEnemies(){
    for(unsigned int i = 0; i < enemies.size(); i++){
        enemies.at(i)->revive();
    }
}

int Area::getRemainingEnemies(){
    int count = 0;
    for(unsigned int i = 0; i < enemies.size(); i++){
        if(!enemies.at(i)->isDead()){
            count++;
        }
    }
    return count;
}
