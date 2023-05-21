#include "Game.h"
#include "ResultState.h"
#include "MenuState.h"
 
ResultState::ResultState(Game *game): State(game, "Result State"){
    game->playMusic(RESULTS);

    // Texto de título
    titleTxt = "RESULTADOS";
    startTxt = "Press SPACE to continue to Main Menu";
    pointsTxt = "Points: " + to_string(game->getPoints());
    timerTxt = "Time: " + game->getTimer();

    // Cargar fuente
    title.load("../../resources/fonts/diesel.ttf", 150);
    titleShadow.load("../../resources/fonts/diesel.ttf", 150);
    points.load("../../resources/fonts/aldo.ttf", 70);
    time.load("../../resources/fonts/aldo.ttf", 70);
    pressStart.load("../../resources/fonts/aldo.ttf", 40);
};

ResultState::~ResultState(){};

void ResultState::update(){ };

void ResultState::draw(){
    // Fondo HUE
    float width = ofGetWidth() / 255.0;
    int brillo = 10;
    int saturation = 4;
    for (int i = 255; i > 0; i--) {
        ofColor c = ofColor(i, saturation, brillo);
        ofSetColor(c);
        ofDrawRectangle((255 - i) * width, 0, width, ofGetHeight());
    }

    ofDrawBitmapString(name, 10, 20);

    // Título
    ofSetColor(64, 64, 64);
    titleShadow.drawString(titleTxt, ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2 + 20,
        ofGetHeight() / 2 - title.stringHeight(titleTxt) / 2 - 50);
    ofSetColor(255, 255, 255);
    title.drawString(titleTxt, ofGetWidth() / 2 - title.stringWidth(titleTxt) / 2,
            ofGetHeight() / 2 - title.stringHeight(titleTxt) / 2 - 30);

    // Tiempo
    time.drawString(timerTxt, ofGetWidth() / 2 - time.stringWidth(timerTxt) / 2,
        ofGetHeight() - time.stringHeight(timerTxt) * 3);

    // Puntos
    points.drawString(pointsTxt, ofGetWidth() / 2 - points.stringWidth(pointsTxt) / 2,
        ofGetHeight() - points.stringHeight(pointsTxt) * 5);

    // Texto de inicio
    ofSetColor(179, 179, 179);
    pressStart.drawString(startTxt, ofGetWidth() / 2 - pressStart.stringWidth(startTxt) / 2,
        ofGetHeight() - pressStart.stringHeight(startTxt) / 3 * 6);
    ofSetColor(255, 255, 255);
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
