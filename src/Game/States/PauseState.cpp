#include "PauseState.h"

PauseState::PauseState(){
    pauseStateImage.load("images/ui/Pause.png");
}

void PauseState::render(){
ofSetColor(200, 200, 200);
pauseStateImage.draw(ofGetWidth()/2 - 200, ofGetHeight()/2 -100, 400, 200);
}

bool PauseState::Paused(){
    return pause;
}

void PauseState::setPause(bool p){
    pause = p;
}       	

void PauseState::keyPressed(int key){
    switch (key){
    case 'p':
    setPause(!pause);
    break;
}
}

void PauseState::reset(){

}

void PauseState::mousePressed(int x, int y, int button){

} 

void PauseState::tick(){

}

