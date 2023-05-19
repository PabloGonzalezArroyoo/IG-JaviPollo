#include "Coin.h"
#include "Player.h"
#include "Game.h"


Coin::Coin(Game *game, vec3 pos, vec3 dim) : GameObject(game, pos, dim){
    material.setDiffuseColor(ofColor::yellow);
    model.loadModel("../../resources/models/coin.fbx");
    model.setPosition(0, 25, 0);
    model.setRotation(0, 90, 1, 0, 0);
    model.setScale(0.1, 0.1, 0.1);
}

Coin::~Coin(){ }

void Coin::update(){
    model.update();
    transform.rotateDeg(4, 0, 1, 0);
}

void Coin::draw(){
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Coin::receiveCarCollision(Player *car){
    car->addCoins(5);
    game->coinSound();
    kill();
}

void Coin::receiveBulletCollision(GameObject *bullet){
    bullet->kill();
    game->coinSound();
    kill();
    game->getPlayer()->addCoins(50);
}
