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
            area->getEnemies().at(i)->tickOverworld();
            if (player->collides(area->getEnemies().at(i)))
            {
                setEnemy(area->getEnemies().at(i));
                setNextState("LoadingState");
                setFinished(true);
            }
        }
    }
    camera->tick();
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
    ofSetColor(255);
	ofDrawBitmapString("Area: "+area->getName()+"\nPlayer Health: "+to_string(player->getHealth())+"\nRemaining enemies: "+to_string(area->getRemainingEnemies()),10,20);
}

void OverworldState::keyPressed(int key)
{
    player->keyPressed(key);

    if(key == 'r'|| key == 'R'){
        area->resetEnemies();
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