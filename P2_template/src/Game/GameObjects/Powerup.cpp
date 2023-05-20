#include "Powerup.h"
#include "Player.h"
#include "Game.h"

Powerup::Powerup(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
    model.loadModel("../../resources/models/powerup.FBX");
    model.setScale(0.15, 0.15, 0.15);
    model.setPosition(15, -85, 0);
    model.setRotation(0, 180, 1, 0, 0);
    
}

Powerup::~Powerup() { }

void Powerup::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Powerup::receiveCarCollision(Player* car) {
    car->boost(2);
    game->playSound(POWERUP);
    this->kill();
}