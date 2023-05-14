#include "Obstacle.h"
#include "Player.h"

Obstacle::Obstacle(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
    material.setEmissiveColor(ofColor::aquamarine);
}
Obstacle::~Obstacle() {}

void Obstacle::draw() {

    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void  Obstacle::receiveCarCollision(Player* car) {
    car->stop();
}

void  Obstacle::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
    this->kill();
};
