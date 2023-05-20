#include "Bomb.h"
#include "Player.h"
#include "Game.h"

Bomb::Bomb(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
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
    this->kill();
}

void Bomb::update() {
    transform.move(transform.getYAxis() * -speed);

    if (transform.getPosition().y < 0) {
        this->kill();
        auto explosion = new Explosion(game, transform.getPosition(), EXPLOSIONS_DIMS);
        game->addGameObject(explosion);
    }
}

void Bomb::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}