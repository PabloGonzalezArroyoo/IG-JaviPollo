#include "Checkpoint.h"
#include "Player.h"
#include "Game.h"

Checkpoint::Checkpoint(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
    material.setEmissiveColor(ofColor::cornflowerBlue);
    transform.rotate(-180, 0, 1, 0);

    position = pos;
    dimensions = dim;
    ofEnableNormalizedTexCoords();
    ofDisableArbTex();
    ofEnableAlphaBlending();
}

Checkpoint::~Checkpoint() { }

void Checkpoint::receiveCarCollision(Player* car) {
    car->setInitPos(position);
    game->playSound(ARCH);
    this->kill();
}

void Checkpoint::draw() {
    material.begin();
    {
        ofDrawBox(position.x, position.y, position.z, ROAD_WIDTH / 6, ROAD_LENGTH, 20);
        //collider->draw();
    }
    material.end();
}