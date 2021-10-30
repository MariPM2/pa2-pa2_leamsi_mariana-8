#include "LoadingState.h"

LoadingState::LoadingState() {
    vector<ofImage> loadingFrames = {};
    timer = 50;
    ofImage temp;
    for (int i = 1; i < 5; i++)
    {
        temp.load("images/ui/Loading" + std::to_string(i == 5 ? 1 : i) + ".png");
        loadingFrames.push_back(temp);
    }

    music.load("audio/ui/LoadingSoundEffect.wav");
    music.setLoop(true);
    music.setVolume(0.25);
    loadingFrames.push_back(temp);

    loadingscreen = new Animation(5, loadingFrames);
    
}

void LoadingState::tick() {
    loadingscreen->tick();
    if(timer<0){
        setFinished(true);
        timer=100;
    }else{
        timer--;
    }
    loadingImage = loadingscreen->getCurrentFrame();
}

void LoadingState::render(){
    loadingImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}

void LoadingState::keyPressed(int key) {

}

void LoadingState::mousePressed(int x, int y, int button) {

}

void LoadingState::reset() {
    setFinished(false);
}
