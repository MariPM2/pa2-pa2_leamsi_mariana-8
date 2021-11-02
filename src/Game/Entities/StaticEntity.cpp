#include "StaticEntity.h"

StaticEntity::StaticEntity(string id, string entityName, int ox, int oy, int ow, int oh): Entity(ox, oy, ow, oh, "images/entities/" + entityName + "pipe.png") {
    this->entityName = entityName;
    this->id = id;
    vector <ofImage> pipes = {};
    ofImage temp;

    temp.load("images/entities/" + entityName + "pipe.png");
    pipes.push_back(temp);

    walkDown = new Animation(1, pipes);
    walkUp = new Animation(1, pipes);
    walkLeft = new Animation(1, pipes);
    walkRight = new Animation(1, pipes);
}

void StaticEntity::tickOverworld(){
    if (moveTimer == 60)
    {
        walking = true;
        switch (direction)
        {
        case Direction::left:
            direction = Direction::down; //up;
            break;
        case Direction::right:
            direction = Direction::up; //down;
            break;
        case Direction::up:
            direction = Direction::left; //right;
            break;
        case Direction::down:
            direction = Direction::right; //left;
            break;
        }
    }
    if (moveTimer == 45)
    {
        walking = false;
    }
    moveTimer--;
    if (moveTimer == 0) moveTimer = 60;

    if (walking)
    {
        switch (direction)
        {
        case Direction::left:
            this->ox = speed;
            walkLeft->tick();
            overworldSprite = walkLeft->getCurrentFrame();
            break;
        case Direction::right:
            this->ox = speed;
            walkRight->tick();
            overworldSprite = walkRight->getCurrentFrame();
            break;
        case Direction::up:
            this->oy = speed;
            walkUp->tick();
            overworldSprite = walkUp->getCurrentFrame();
            break;
        case Direction::down:
            this->oy = speed;
            walkDown->tick();
            overworldSprite = walkDown->getCurrentFrame();
            break;
        }
    }
    else
    {
        switch (direction)
        {
        case Direction::left:
            overworldSprite.load("images/entities/" + entityName + "pipe.png");
            break;
        case Direction::right:
            overworldSprite.load("images/entities/" + entityName + "pipe.png");
            break;
        case Direction::up:
            overworldSprite.load("images/entities/" + entityName + "pipe.png");
            break;
        case Direction::down:
            overworldSprite.load("images/entities/" + entityName + "pipe.png");
            break;
        }
    }
}

void StaticEntity::renderOverworld(){
    overworldSprite.draw(renderX, renderY, ow, oh);
}

void StaticEntity::keyPressed(int key)
{
}

void StaticEntity::keyReleased(int key)
{
}

ofRectangle StaticEntity::getBounds(){
    return ofRectangle(ox,oy,ow,oh);
}

ofRectangle StaticEntity::getBounds(int ox, int oy){
    return ofRectangle(ox,oy,ow,oh);
}


void StaticEntity::reset()
{
}