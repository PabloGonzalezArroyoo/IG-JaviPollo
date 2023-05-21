#include "Airplane.h"
#include "Player.h"
#include "Game.h"

Airplane::Airplane(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim), timer(0), bTurned(false) {
    model.loadModel("../../resources/models/plane.fbx");
    model.setRotation(0, 180, 1, 0, 0);
    model.setScale(0.6, 0.6, 0.6);

    transform.rotateDeg(90, 0, 1, 0);
    speed = 6;
}

Airplane::~Airplane() {}

void Airplane::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Airplane::update() {
    transform.move(transform.getZAxis() * -speed);
    bTurned = false;

    if (transform.getPosition().x > ROAD_WIDTH / 2 + 20 ||
        transform.getPosition().x < -ROAD_WIDTH / 2 - 20) {
        turn();
    }

    timer += ofGetLastFrameTime();

    if (timer > 1.8) {
        auto bomb = new Bomb(game, transform.getPosition(), BOMBS_DIMS);
        game->addGameObject(bomb);
        timer = 0;
    }
}

void Airplane::turn() {
    if (!bTurned) {
        transform.rotateDeg(180, 0, 1, 0);
        transform.move(transform.getZAxis() * -speed);
        bTurned = true;
    }
}

void Airplane::receiveCarCollision(Player* car) {
    car->stop();
}
