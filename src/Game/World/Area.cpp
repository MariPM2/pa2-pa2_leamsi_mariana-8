#include "Area.h"

<<<<<<< HEAD
Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<StaticEntity*> staticEntity, vector<Friend*> friends)
=======
Area::Area(Area *nextArea, string areaImagePath, string areaMusicPath, string areaStagePath, ofPoint entrancePosition, vector<Enemy*> enemies, string name, vector<StaticEntity*> staticEntity, vector<Friend*> friends)
>>>>>>> 3d2dc8963e0ec57fdcf130d38541749e51c9e512
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
    this->staticEntity = staticEntity;
    this->friends = friends;
>>>>>>> 3d2dc8963e0ec57fdcf130d38541749e51c9e512
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
