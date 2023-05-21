#include "Claw.h"
#include "Player.h"

Claw::Claw(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
    material.setEmissiveColor(ofColor::lawnGreen);
    speed = 1;
    initYPos = pos.y;
}
Claw::~Claw() {}

void Claw::update() {
    vec3 pos = collider->getPosition();
    collider->setPosition(vec3(pos.x, pos.y + speed, pos.z));
    pos = collider->getPosition();

    if (pos.y >= initYPos + 50) speed = -1;
    else if (pos.y == initYPos - 200) speed = 1;
}

void Claw::draw() {
    material.begin();
    {
        collider->draw();
    }
    material.end();
}

void Claw::receiveCarCollision(Player* car) {
    car->stop();
    car->setCoins(0);
}

void Claw::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
    this->kill();
};
