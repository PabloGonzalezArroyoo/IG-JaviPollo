#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"

 
ResultState::ResultState(Game *game): State(game, "Result State"){
    game->playMusic(RESULTS);
};

ResultState::~ResultState(){};

void ResultState::update(){ };

void ResultState::draw(){
    ofBackground(127);
    ofDrawBitmapString(name, 10, 20);
};

void ResultState::keyPressed(int key) {
    if (key == ' ') {
        game->stopMusic(RESULTS);
        game->playMusic(MENU);
        game->playerWins(false);
        game->getGameStateMachine()->popState();
    }
}
