#include "Airplane.h"
#include "Player.h"
#include "Game.h"

Airplane::Airplane(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim), timer(0), bTurned(false),
    canGenerate(true) {
    model.loadModel("../../resources/models/plane.fbx");
    model.setRotation(0, 180, 1, 0, 0);
    model.setScale(0.6, 0.6, 0.6);

    transform.rotateDeg(90, 0, 1, 0);
    speed = 6;

    bomb = new Bomb(game, vec3(0, 10000, 0), BOMBS_DIMS, this);
    explosion = new Explosion(game, vec3(0, 10000, 0), EXPLOSIONS_DIMS, this);
    game->addGameObject(bomb);
    game->addGameObject(explosion);
}

Airplane::~Airplane() {}

void Airplane::draw() {
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
}

void Airplane::generateBombs() {
    bomb->setActive(true);
    bomb->setPosition(transform.getPosition());

    canGenerate = false;
}

void Airplane::update() {
    transform.move(transform.getZAxis() * -speed);
    bTurned = false;

    if (transform.getPosition().x > ROAD_WIDTH / 2 + 20 ||
        transform.getPosition().x < -ROAD_WIDTH / 2 - 20) {
        turn();
    }

    if (canGenerate) timer += ofGetLastFrameTime();

    if (timer > 1.8) {
        generateBombs();
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

void Airplane::createExplosion(vec3 pos) {
    explosion->setActive(true);
    explosion->setPosition(pos);
}
