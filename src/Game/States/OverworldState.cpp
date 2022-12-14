#include "OverworldState.h"

OverworldState::OverworldState(Player *player, Area *area)
{
    this->player = player;
    camera = new OverworldCamera(player);
    loadArea(area);
    music.setVolume(0.25);
    music.setLoop(true);
    afterLoadingState="Battle";
    pauseState = new PauseState();
    player->setEnt(area->getStaticEntities());
    player->sefF(area->getFriends());
}

void OverworldState::loadArea(Area *area)
{
    this->area = area;
    overworldImage = area->getImage();
    music = area->getMusic();
    music.setVolume(0.25);
    music.setLoop(true);
    player->setOX(area->getEntrancePos().x);
    player->setOY(area->getEntrancePos().y);
    area->getEnemies().back()->kill();
    area->BossIsDead=false;
    enemigo=area->getRemainingEnemies();
}

void OverworldState::tick()
{
    if(!pauseState->Paused()){
        player->tickOverworld();
    }   

    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            Enemy* enemy=area->getEnemies().at(i);
            enemy->tickOverworld();
            
            if (player->collides(area->getEnemies().at(i)))
            {
                setEnemy(area->getEnemies().at(i));
                setNextState("LoadingState");
                enemigo-=1;
                setFinished(true);
                if(enemigo==0){
                    area->getEnemies().back()->revive();
                }
                Boss* boss=dynamic_cast<Boss*>(enemy);
                if(boss!=nullptr){
                    area->BossIsDead=true;
                }
            }
        }
    }
    camera->tick();

    for(unsigned int i=0; i<area->getFriends().size();i++){
        area->getFriends().at(i)->tickOverworld();
    }

    for(unsigned int i=0; i<area->getStaticEntities().size();i++){
        area->getStaticEntities().at(i)->tickOverworld();
    }

    
}

void OverworldState::render()
{
    overworldImage.drawSubsection(0, 0, camera->getDimensionX(), camera->getDimensionY(), camera->getLeftCornerX(), camera->getTopCornerY());
    player->renderOverworld();

    if(pauseState->Paused() == true){
        pauseState->render();
    }

    for (unsigned int i = 0; i < area->getEnemies().size(); i++)
    {
        if (!area->getEnemies().at(i)->isDead())
        {
            int playerDistanceX = area->getEnemies().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getEnemies().at(i)->getOY() - camera->getPlayerY();
            area->getEnemies().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getEnemies().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getEnemies().at(i)->renderOverworld();
        }
    }

    for(unsigned int i=0; i<area->getFriends().size();i++){
        int playerDistanceX = area->getFriends().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getFriends().at(i)->getOY() - camera->getPlayerY();
            area->getFriends().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getFriends().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getFriends().at(i)->renderOverworld();
    }

    for(unsigned int i=0; i<area->getStaticEntities().size();i++){
        int playerDistanceX = area->getStaticEntities().at(i)->getOX() - camera->getPlayerX();
            int playerDistanceY = area->getStaticEntities().at(i)->getOY() - camera->getPlayerY();
            area->getStaticEntities().at(i)->setRenderX(camera->getDimensionX() / 2 + playerDistanceX);
            area->getStaticEntities().at(i)->setRenderY(camera->getDimensionY() / 2 + playerDistanceY);
            area->getStaticEntities().at(i)->renderOverworld();
    }

    ofSetColor(6,14,255);
	ofDrawBitmapString("Area: "+area->getName()+"\nPlayer Health: "+to_string(player->getHealth())+"\nRemaining enemies: "+to_string(area->getRemainingEnemies()),10,20);
    ofSetColor(255,255,255);
}

void OverworldState::keyPressed(int key)
{
    player->keyPressed(key);

    if(key == 'r'|| key == 'R'){
        area->resetEnemies();
    }
    for(unsigned int i=0; i<area->getFriends().size();i++){
        if(key == 'e' || key == 'E'){
            if(player->collides(area->getFriends().at(i))){
                area->getFriends().at(i)->talking=true;
            }
        }
    }

    pauseState->keyPressed(key);
}

void OverworldState::keyReleased(int key)
{
    player->keyReleased(key);
}

void OverworldState::mousePressed(int x, int y, int button)
{
}

void OverworldState::reset()
{
    player->keyReleased('w');
    player->keyReleased('a');
    player->keyReleased('s');
    player->keyReleased('d');
    setFinished(false);
    setNextState("");
}