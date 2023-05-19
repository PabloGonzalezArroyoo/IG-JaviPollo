#include "PlayState.h"
#include "ResultState.h"
#include "PauseState.h"
#include "Player.h"

PlayState::PlayState(Game *game) : State(game, "Play State"){
    game->init();
};

void PlayState::update(){
    if (!game->getPlayer()->isOiled()) {
        if (ofGetKeyPressed(OF_KEY_LEFT))
            game->getPlayer()->steerLeft();
        if (ofGetKeyPressed(OF_KEY_RIGHT))
            game->getPlayer()->steerRight();
        if (ofGetKeyPressed(OF_KEY_UP))
            game->getPlayer()->accelerate();
        if (ofGetKeyPressed(OF_KEY_DOWN))
            game->getPlayer()->brake();
    }

    game->update();
};
    
void PlayState::draw(){
    ofBackground(7, 19, 54);

    ofPushMatrix();
    {
        ofTranslate(10, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString("Fps: " + ofToString(ofGetFrameRate()), 0, 0);
        ofTranslate(0, 20);
        ofDrawBitmapString(name, 0, 0);
    }
    ofPopMatrix();
    game->draw();
};

void PlayState::keyPressed(int key){
    if(key == 'l')
        game->getPlayer()->toggleLight();
    if(key == 'd')
        game->toggleDebug();
    if(key == ' ')
        if (game->getPlayer()->getCoins() > 0) game->getPlayer()->shoot();
    if (key == 'p') {
        game->getGameStateMachine()->pushState(new PauseState(game));
    }
}
