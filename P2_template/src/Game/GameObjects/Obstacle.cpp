#include "Obstacle.h"
#include "Player.h"

Obstacle::Obstacle(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
    material.setEmissiveColor(ofColor::aquamarine);
    model.loadModel("../../resources/models/cone.fbx");
    model.setPosition(0, -26, 400);
    model.setRotation(0, 180, 1, 0, 0);
    model.setScale(0.2, 0.2, 0.2);
}
Obstacle::~Obstacle() {}

void Obstacle::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void  Obstacle::receiveCarCollision(Player* car) {
    car->stop();
}

void  Obstacle::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
    this->kill();
};
