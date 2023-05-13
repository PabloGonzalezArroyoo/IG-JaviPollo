#include "Explosion.h"
#include "Player.h"

Explosion::Explosion(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim), timer(0) {
    //material.setEmissiveColor(ofColor::cornflowerBlue);

}

Explosion::~Explosion() { }

void Explosion::receiveCarCollision(Player* car) {
    for (int i = 0; i < 180; i++) car->transform.rotateDeg(1, 0, 2, 0);
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
    //material.begin();
    {
        collider->draw();
    }
    //material.end();
}