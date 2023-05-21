#include "Bomb.h"
#include "Player.h"
#include "Game.h"
#include "Airplane.h"

Bomb::Bomb(Game* game, vec3 pos, vec3 dim, Airplane* pg) : GameObject(game, pos, dim), active(false),
    generator(pg) {
    material.setEmissiveColor(ofColor::paleVioletRed);
    model.loadModel("../../resources/models/tnt.fbx");
    model.setScale(0.1, 0.1, 0.1);
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -20, 0);
}

Bomb::~Bomb() { }

void Bomb::receiveCarCollision(Player* car) {
    car->setToInitPos();
    game->playSound(EXPLOSION);
    deactivateBomb();
    notifyGenerator();
}

void Bomb::update() {
    if (active) {
        transform.move(transform.getYAxis() * -speed);

        if (transform.getPosition().y < 0) {
            generator->createExplosion(transform.getPosition());
            deactivateBomb();
        }
    }
}

void Bomb::draw() {
    if (active) {
        transform.transformGL();
        model.drawFaces();
        transform.restoreTransformGL();
    }
}

void Bomb::deactivateBomb() {
    setPosition(vec3(0, 10000, 0));
    setActive(false);
}

void Bomb::notifyGenerator() {
    if (generator != nullptr) generator->setGenerate();
}