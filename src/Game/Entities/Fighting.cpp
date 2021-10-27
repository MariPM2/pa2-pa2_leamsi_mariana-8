#include "Fighting.h"
// #include "Animation.h"
#include <iostream>
using namespace std;

Fighting::Fighting(int ox, int oy, int ow, int oh, int fx, int fy, int fw, int fh, int health, int baseDamage, string fightingPath, string overworldPath) : Entity(ox,oy,ow,oh,overworldPath){
    this->fx=fx;
    this->fy=fy;
    this->fw=fw;
    this->fh=fh;
    this->health=health;
    this->baseDamage = baseDamage;
    fightingSprite.draw(fx,fy,fw,fh);
}

void Fighting::renderFighting(){
    fightingSprite.draw(fx,fy,fw,fh);
}
void Fighting::tickFighting(){
    fightingSprite = fighting->getCurrentFrame();
    fighting->tick();
}