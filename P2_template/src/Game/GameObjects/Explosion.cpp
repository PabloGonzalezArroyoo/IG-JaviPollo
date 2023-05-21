#include "Explosion.h"
#include "Player.h"
#include "Game.h"
#include "Airplane.h"

Explosion::Explosion(Game* game, vec3 pos, vec3 dim, Airplane* pg) : GameObject(game, pos, dim), timer(0),
    generator(pg), active(false) {
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
    deactivateExplosion();
}

void Explosion::update() {
    if (active) {
        timer += ofGetLastFrameTime();

        if (timer > 1) {
            deactivateExplosion();
            timer = 0;
        }
    }
}

void Explosion::draw() {
    if (active) {
        transform.transformGL();
        model.drawFaces();
        transform.restoreTransformGL();
    }
}

void Explosion::notifyGenerator() {
    if (generator != nullptr) generator->setGenerate();
}

void Explosion::deactivateExplosion() {
    setPosition(vec3(0, 10000, 0));
    setActive(false);
    notifyGenerator();
}