#include "LoadingState.h"

LoadingState::LoadingState() {
    vector<ofImage> loadingFrames;
    timer = 50;
    ofImage temp;
    temp.load("images/ui/loading1.png");
    music.load("audio/ui/boop.wav");
    music.setLoop(true);
    music.setVolume(0.25);
    loadingFrames.push_back(temp);

    loadingscreen = new Animation(1, loadingFrames);
    
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
