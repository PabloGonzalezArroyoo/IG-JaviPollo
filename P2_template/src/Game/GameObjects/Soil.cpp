#include "Soil.h"
#include "Player.h"

Soil::Soil(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    material.setEmissiveColor(ofColor::brown);

    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
}

Soil::~Soil() { }

void Soil::receiveCarCollision(Player* car) {
    car->setSoiled();
}

void Soil::draw() {
    material.begin();
    {
        plane.draw();
    }
    material.end();
}