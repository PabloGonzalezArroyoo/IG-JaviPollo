#include "Crane.h"
#include "Player.h"
#include "Game.h"

Crane::Crane(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim) {
    material.setEmissiveColor(ofColor::lawnGreen);
    vec3 sujPos = pos + vec3(0, dim.y / 2, 0);
    sujecion = new GameObject(game, sujPos, vec3(dim.y, dim.x - 30, dim.z));
    gancho = new Claw(game, sujPos + vec3(dim.y / 2 - 40, -dim.y / 2 + 90, 0), vec3(50, dim.y - 250, 50));
    game->addGameObject(gancho);
}
Crane::~Crane() {}

void Crane::update() {
    transform.rotateDeg(1, 0, 1, 0);
    sujecion->transform.rotateDeg(1, 0, 1, 0);
    gancho->transform.rotateAroundDeg(1, vec3(0, 1, 0), transform.getPosition());
}

void Crane::draw() {
    material.begin();
    {
        collider->draw();
        sujecion->getCollider()->draw();
        gancho->draw();
    }
    material.end();
}

void Crane::receiveCarCollision(Player* car) {
    car->stop();
}

void Crane::receiveBulletCollision(GameObject* bullet) {
    bullet->kill();
};
