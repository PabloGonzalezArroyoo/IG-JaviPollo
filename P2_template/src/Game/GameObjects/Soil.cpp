#include "Soil.h"
#include "Player.h"

Soil::Soil(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
    ofEnableAlphaBlending();
    ofDisableArbTex();
    ofLoadImage(texture, "../../resources/images/dirt.png");
    texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
}

Soil::~Soil() { }

void Soil::receiveCarCollision(Player* car) {
    car->setSoiled();
}

void Soil::draw() {
    texture.bind();
    plane.draw();
    texture.unbind();
}