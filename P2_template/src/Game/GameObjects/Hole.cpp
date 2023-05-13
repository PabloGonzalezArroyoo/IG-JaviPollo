#include "Hole.h"
#include "Player.h"

Hole::Hole(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
    ofEnableAlphaBlending();
    ofDisableArbTex();
    ofLoadImage(texture, "hole.png");
}

Hole::~Hole() { }

void Hole::receiveCarCollision(Player* car) {
    auto carCollider = this->getCollider();
    auto holeCollider = this->getCollider();
    glm::vec3 carPos = carCollider->getPosition();
    glm::vec3 holePos = holeCollider->getPosition();
    
    /*if (carPos.x > holePos.x && carPos.x < holePos.x + holeCollider->getSize().x &&
        carPos.z < holePos.z && carPos.z < holePos.z + holeCollider->getSize().z) {
        car->setToInitPos();
    }*/
    car->setToInitPos();
}

void Hole::draw() {
    texture.bind();
    plane.draw();
    texture.unbind();
}