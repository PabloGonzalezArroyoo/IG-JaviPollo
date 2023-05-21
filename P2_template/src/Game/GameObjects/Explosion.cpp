#include "Explosion.h"
#include "Player.h"
#include "Game.h"

Explosion::Explosion(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim), timer(0) {
    //material.setEmissiveColor(ofColor::cornflowerBlue);
    model.loadModel("../../resources/models/explosion.obj");
    model.setRotation(0, 180, 1, 0, 0);
    model.setScale(0.5, 0.5, 0.5);
    model.setPosition(0, -54, 0);
}

Explosion::~Explosion() { }

void Explosion::receiveCarCollision(Player* car) {
    car->transform.rotate(180, 0, 1, 0);
    game->playSound(EXPLOSION);
    this->kill();
}

void Explosion::update() {
    timer += ofGetLastFrameTime();

    if (timer > 1) {
        this->kill();
        timer = 0;
    }
}

void Explosion::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}