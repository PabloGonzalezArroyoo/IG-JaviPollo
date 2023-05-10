#include "Oil.h"
#include "Player.h"

Oil::Oil(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    material.setEmissiveColor(ofColor::yellowGreen);

    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
}

Oil::~Oil() { }

void Oil::receiveCarCollision(Player* car) {
    car->setOiled();
}

void Oil::draw() {
    material.begin();
    {
        plane.draw();
    }
    material.end();
}