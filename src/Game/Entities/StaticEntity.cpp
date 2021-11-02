#include "StaticEntity.h"

StaticEntity::StaticEntity(string id, string entityName, int ox, int oy, int ow, int oh, string overworldPath): Entity(ox, oy, ow, oh, overworldPath) {
    this->entityName = entityName;
    this->id = id;
}

void StaticEntity::tickOverworld(){
    overworldSprite.load("images/entities/static" + entityName + "pipe1.png");
}

void StaticEntity::renderOverworld(){
    overworldSprite.draw(renderX, renderY, ow, oh);
}