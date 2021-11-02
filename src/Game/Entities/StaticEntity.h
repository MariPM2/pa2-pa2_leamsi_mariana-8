#pragma once

#include "Entity.h"
#include "Animation.h"

class StaticEntity: public Entity{

private:
string id;
string entityName;
ofImage sprite;
int renderX = 1000;
int renderY = 1000;
bool walking = false;
int speed = 0;
Animation *staticEntity;
Direction direction = Direction::down;
Animation *walkUp;
Animation *walkDown;
Animation *walkLeft;
Animation *walkRight;
int moveTimer;

public:

StaticEntity(string id, string entityName, int ox, int oy, int ow, int oh);
int getOX() { return ox; };
int getOY() { return oy; };
void setRenderX(int x){  renderX = x; };
void setRenderY(int y){  renderY = y; };
void tickOverworld();
void renderOverworld();
void keyPressed(int key);
void keyReleased(int key);
void reset();
string getId(){ return id; };
ofImage getSprite() { return overworldSprite;};
ofRectangle getBounds();
ofRectangle getBounds(int ox,int oy);
};