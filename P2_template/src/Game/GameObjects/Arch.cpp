#include "Arch.h"
#include "Player.h"

Arch::Arch(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim), coinsNumber(0) {
    material.setEmissiveColor(ofColor::cornflowerBlue);

}

Arch::~Arch() { }

void Arch::receiveCarCollision(Player* car) {
    car->addCoins(coinsNumber);
    this->kill();
}

void Arch::update() {
    coinsNumber = rand() % 100 + 1;
}

void Arch::draw() {
    material.begin();
    {
        collider->draw();
    }
    material.end();
}