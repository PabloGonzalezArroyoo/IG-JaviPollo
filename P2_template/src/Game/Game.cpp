#include "Game.h"
#include "Player.h"
#include "PlayState.h"
#include "ResultState.h"

Game::Game(){
    // TODO create settings
    gsm = new GameStateMachine();

    srand(time(0));

    generator = new GameObjectGenerator(this);
    bDebug = false;
    win = false;
    scream.load("../../resources/sounds/aaa.wav");
    timer = 0;

    speed.loadFont("../../resources/fonts/aldo.ttf", 30);
    coins.loadFont("../../resources/fonts/aldo.ttf", 30);
    timerF.loadFont("../../resources/fonts/aldo.ttf", 30);
}

Game::~Game(){
    ofLogNotice() << "Deleting game";
    delete gameObjects;
    delete generator;
    delete currentState();
    delete gsm;
}

void Game::init(){
    
    if(gameObjects != nullptr)
        delete gameObjects;
    
    
    gameObjects = new GameObjectContainer();
    
    player = new Player(this);
    player->init();

    cam.setPosition(0, 300, -600);
    cam.setTarget(player->transform);
    cam.setParent(player->transform);
    //cam.disableMouseInput();
    cam.setFarClip(100000);
    
    gameObjects->add(player);
    generator->generateWorld();
}

void Game::update(){
    if (dynamic_cast<PlayState*>(gsm->currentState()) != nullptr) {
        gameObjects->update();
        timer += ofGetLastFrameTime();
    }

    if (win) gsm->changeState(new ResultState(this));
}

void Game::draw(){
    ofEnableLighting();
    ofEnableDepthTest();
    
    drawHUD();
    
    cam.begin();
    {
        if(bDebug) gameObjects->drawDebug();
        else gameObjects->draw();
    }
    cam.end();
    
    ofDisableLighting();
    ofDisableDepthTest();
}

void Game::drawHUD() {
    ofPushMatrix();
    {
        ofTranslate(0, ofGetHeight() - 60);

        ofSetColor(255);
        string text = twoDecimalFloatString(getEllapsedTime());
        timerF.drawString("Time: " + text, 10, 45);

        text = to_string(getPlayer()->getCoins());
        coins.drawString(text, ofGetWidth() / 2 - coins.stringWidth(text) / 2, 45);

        text = twoDecimalFloatString(getPlayer()->getSpeed());
        speed.drawString("Speed: " + text + " u/s", ofGetWidth() - 90 * 3, 45);

        ofSetColor(0);
        ofDrawRectangle(0, 5, ofGetWidth(), 55);
        ofSetColor(255);
        ofDrawRectangle(0, 0, ofGetWidth(), 60);
    }
    ofPopMatrix();
}

string Game::twoDecimalFloatString(float f) {
    string toString = to_string(f);
    string endText = "";
    int i = 0; bool fin = false;

    while (i < toString.size() && !fin) {
        endText += toString[i];
        if (toString[i] == '.') {
            for (int k = i + 1; k < i + 3; k++) endText += toString[k];
            fin = true;
        }
        i++;
    }

    return endText;
}

Player * Game::getPlayer(){
    return player;
}

vector<GameObject *> Game::getCollisions(GameObject *gameObject){
    return gameObjects->getCollisions(gameObject);
}

void Game::addGameObject(GameObject *gameobject){
    gameObjects->add(gameobject);
}

void Game::toggleDebug(){
    bDebug = !bDebug;
}

void Game::playerWins() {
    win = true;
}

float Game::getEllapsedTime(){
    return timer;
}

void Game::doScream(){
    scream.play();
}
