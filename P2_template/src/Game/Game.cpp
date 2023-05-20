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
    timer = 0; points = 0;

    speed.loadFont("../../resources/fonts/aldo.ttf", 30);
    coins.loadFont("../../resources/fonts/aldo.ttf", 30);
    timerF.loadFont("../../resources/fonts/aldo.ttf", 30);
    
    // SONIDOS
    ofSoundPlayer coin;
    ofSoundPlayer explosion;
    ofSoundPlayer hole;
    ofSoundPlayer oil;
    ofSoundPlayer powerup;
    ofSoundPlayer shoot;
    ofSoundPlayer soil;
    ofSoundPlayer arch;
    ofSoundPlayer train;

    coin.load("../../resources/sounds/coin.wav"); sounds.push_back(coin);
    explosion.load("../../resources/sounds/explosion.mp3"); sounds.push_back(explosion);
    hole.load("../../resources/sounds/hole.wav"); sounds.push_back(hole);
    oil.load("../../resources/sounds/oil.wav"); sounds.push_back(oil);
    powerup.load("../../resources/sounds/powerup.wav"); sounds.push_back(powerup);
    shoot.load("../../resources/sounds/shoot.wav"); sounds.push_back(shoot);
    soil.load("../../resources/sounds/soil.wav"); sounds.push_back(soil);
    arch.load("../../resources/sounds/arch.mp3"); sounds.push_back(arch);
    train.load("../../resources/sounds/train.mp3"); sounds.push_back(train);

    // MÚSICA
    ofSoundPlayer menu;
    ofSoundPlayer playstate;
    ofSoundPlayer pause;
    ofSoundPlayer results;
    menu.load("../../resources/music/menu.mp3"); menu.setLoop(true); musics.push_back(menu);
    playstate.load("../../resources/music/playstate.mp3"); playstate.setLoop(true); playstate.setVolume(0.7); musics.push_back(playstate);
    pause.load("../../resources/music/pause.mp3"); pause.setLoop(true); musics.push_back(pause);
    results.load("../../resources/music/results.mp3"); results.setLoop(true); musics.push_back(results);
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
    gameObjects->update();
    timer += ofGetLastFrameTime();

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

void Game::playerWins(bool w) {
    win = w;
}

float Game::getEllapsedTime(){
    return timer;
}

void Game::doScream(){
    scream.play();
}
