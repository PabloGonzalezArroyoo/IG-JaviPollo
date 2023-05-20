#include "Hole.h"
#include "Player.h"
#include "Game.h"

Hole::Hole(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
    plane.setParent(transform);
    transform.rotateDeg(-90, 1, 0, 0);
    plane.set(dim.x, dim.z);
    ofEnableAlphaBlending();
    ofDisableArbTex();
    ofLoadImage(texture, "../../resources/images/hole.png");
}

Hole::~Hole() { }

void Hole::receiveCarCollision(Player* car) {    
    car->setToInitPos();
    game->playSound(HOLE);
}

void Hole::draw() {
    texture.bind();
    plane.draw();
    texture.unbind();
}