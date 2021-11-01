#include "Boss.h"

Boss::Boss(string id, int health, int baseDamage, string entityName, int ox, int oy, string fightingPath, string overworldPath) : Enemy(id, health, baseDamage, entityName, ox, oy)
{}


Boss::~Boss()
{
    delete walkUp;
    delete walkDown;
    delete walkLeft;
    delete walkRight;
    delete fighting;
}

void Boss::phase(){
    PhasePass=true;
}