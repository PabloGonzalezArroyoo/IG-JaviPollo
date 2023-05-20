#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"
 
ResultState::ResultState(Game *game): State(game, "Result State"){
    game->playMusic(RESULTS);

    // Texto de título
    titleTxt = "RESULTADOS";
    startTxt = "Press SPACE to start";
    pointsTxt = "Points: " + to_string(game->getPoints());

    // Cargar fuente
    title.load("../../resources/fonts/diesel.ttf", 150);
    points.load("../../resources/fonts/aldo.ttf", 70);
    pressStart.load("../../resources/fonts/aldo.ttf", 70);
};

ResultState::~ResultState(){};

void ResultState::update(){ };

void ResultState::draw(){
    ofBackground(127);
    ofDrawBitmapString(name, 10, 20);

    title.drawString(titleTxt, ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2,
        ofGetHeight() / 2 - title.stringHeight(titleTxt) * 1.5);
    points.drawString(pointsTxt, ofGetWidth() / 2 - points.stringWidth(pointsTxt) / 2,
        ofGetHeight() - points.stringHeight(pointsTxt) * 3);
};

void ResultState::keyPressed(int key) {
    if (key == ' ') {
        game->stopMusic(RESULTS);
        game->playMusic(MENU);
        game->playerWins(false);
        game->addPoints(-game->getPoints());
        game->getGameStateMachine()->popState();
    }
}
