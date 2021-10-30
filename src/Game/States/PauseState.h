#pragma once

#include "State.h"

class PauseState : public State{

private:

ofImage pauseStateImage;
bool pause = false;

public:

PauseState();
void render();
void setPause(bool p);
bool Paused();
void reset();
void keyPressed(int key);
void keyReleased();
void tick();
void mousePressed(int x, int y, int button);
};
