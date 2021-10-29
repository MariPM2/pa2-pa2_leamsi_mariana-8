#pragma once

#include "State.h"
#include "Animation.h"

class LoadingState : public State
{
    private:
        ofImage loadingImage;
        Animation *loadingscreen;
    public:
        LoadingState();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y, int button);
        void reset();
        int timer;
};