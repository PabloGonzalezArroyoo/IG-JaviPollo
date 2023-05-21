
#include "Train.h"
#include "Player.h"
#include "Game.h"

Train::Train(Game* game, glm::vec3 pos, glm::vec3 dim, TrainGenerator* pg) : GameObject(game, pos, dim),
    generator(pg), active(false), life(3) {
    model.loadModel("../../resources/models/train.fbx");

    collider->move(0, dim.y / 2 - 25, 0);
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -25, 0);
    model.setScale(0.8, 0.8, 0.8);

    transform.rotateDeg(90, 0, 1, 0);
    speed = 35;
}

Train::~Train() { }

void Train::update() {
    if (active) {
        model.update();
        transform.move(transform.getZAxis() * -speed);

        if (transform.getPosition().x < -ROAD_WIDTH * 2) deactivateTrain();
    }
};

void Train::draw() {
    if (active) {
        transform.transformGL();
        model.drawFaces();
        transform.restoreTransformGL();
    }
};

void Train::deactivateTrain() {
    setPosition(vec3(0, 10000, 0));
    setActive(false);
    notifyGenerator();
    life = TRAIN_MAX_LIFE;
}

void Train::receiveCarCollision(Player* car) {
    car->setToInitPos();
    game->playSound(TRAIN);
    deactivateTrain();
};

void Train::receiveBulletCollision(GameObject* bullet) {
    life--;
    if (life <= 0) {
        deactivateTrain();
        game->getPlayer()->addCoins(1000);
    }
    game->playSound(TRAIN);
    bullet->kill();    
};

void Train::notifyGenerator() {
    if (generator != nullptr) generator->setGenerate();
}
