#include "Player.h"
#include "Game.h"
#include "Bullet.h"

Player::Player(Game *game) : GameObject(game, glm::vec3(100)), oiled(false), oilTime(0), auxFactor(1), turnTime(0),
    soiled(false) {
    
    material.setDiffuseColor(ofColor::blue);
    
    faro.setParent(transform);
    faro.setDiffuseColor(ofColor::yellow);
    faro.setSpotlight();
    faro.move(0, 0, 50);
    faro.rotateDeg(-200, 1, 0, 0);
}

Player::~Player(){}

void Player::init(){
    transform.setPosition(0, 0, 0);
    speed = 0;
    bLight = true;
    iniPos = collider->getPosition();
    coins = 0;
}

void Player::update(){
    prevPos = transform.getPosition();
    transform.move(transform.getZAxis() * speed);
    
    if (soiled) {
        if (speed < 10) speed *= 0.9;
        else if (speed < 30) speed *= 0.8;
        else speed *= 0.7;
        soiled = false;
    }

    if(speed > MAX_SPEED) speed = MAX_SPEED;
    if(speed < 0) speed = 0;

    if (oiled) oilMovement();
}

void Player::draw(){
    
    faro.draw();
    if(bLight)
        faro.enable();
    else
        faro.disable();
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Player::drawDebug(){
    collider->drawDebug();
    
    transform.transformGL();
    ofDrawAxis(100);
    transform.restoreTransformGL();
}

void Player::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveCarCollision(this);
    }
}

void Player::steerLeft(){
    transform.rotateDeg(1, 0, 2, 0);
}
void Player::steerRight(){
    transform.rotateDeg(-1, 0, 2, 0);
}
void Player::accelerate(){
    speed += 0.1;
}
void Player::brake(){
    speed -= 0.1;
}

void Player::stop(){
    speed = 0;
    transform.setPosition(prevPos);
}

void Player::toggleLight(){
    bLight = !bLight;
}

float Player::getSpeed(){
    return speed;
}

void Player::addCoins(int n){
    coins += n;
}

int Player::getCoins(){
    return coins;
}
void Player::shoot(){
    coins--;
    game->addGameObject(new Bullet(game, transform));
}

void Player::oilMovement() {
    oilTime += ofGetLastFrameTime();
    
    if (oilTime < 2) {
        turnTime += ofGetLastFrameTime();
        if ((turnTime < 0.5) || (turnTime > 1.0 && turnTime < 1.5)) {
            transform.rotateDeg(1.2, 0, 2, 0);
        }
        else transform.rotateDeg(-1.3, 0, 2, 0);
    }
    else {
        oilTime = 0;
        oiled = false;
        turnTime = 0;
    }
}