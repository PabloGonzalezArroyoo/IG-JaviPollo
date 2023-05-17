#include "Oil.h"
#include "Player.h"

Oil::Oil(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);

    ofEnableAlphaBlending();
    ofDisableArbTex();
    ofLoadImage(texture, "../../resources/images/oil.png");
}

void Oil::draw() {
    texture.bind();
    plane.draw();
    texture.unbind();
}

Oil::~Oil() { }

void Oil::receiveCarCollision(Player* car) {
    car->setOiled();
}

