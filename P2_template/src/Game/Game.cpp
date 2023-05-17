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

    if (win) {
        gsm->changeState(new ResultState(this));
    }
}

void Game::draw(){
    if (dynamic_cast<PlayState*>(gsm->currentState()) != nullptr) {
        ofEnableLighting();
        ofEnableDepthTest();
        
        cam.begin();
        {
            if(bDebug) gameObjects->drawDebug();
            else gameObjects->draw();
        }
        cam.end();
    
        ofDisableLighting();
        ofDisableDepthTest();
    }
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
