#include "Barrier.h"
#include "Player.h"

Barrier::Barrier(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim), initialYPos(pos.y), factor(-1) {
    material.setEmissiveColor(ofColor::darkorange);
}

Barrier::~Barrier() {}

void Barrier::draw() {

    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void  Barrier::receiveCarCollision(Player* car) {
    car->stop();
}

void  Barrier::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
    this->kill();
};

void Barrier::update() {
    vec3 pos = collider->getPosition();
    collider->setPosition(vec3(pos.x, pos.y + factor, pos.z));
    pos = collider->getPosition();

    if (pos.y <= initialYPos - 150) factor = 1;
    else if (pos.y == initialYPos) factor = -1;
}