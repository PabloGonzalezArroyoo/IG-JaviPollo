#include "TrainGenerator.h"
#include "Game.h"

TrainGenerator::TrainGenerator(Game* g, vec3 p) : GameObject(g, p), time(0), canGenerate(true),
position(p) {
    train = new Train(game, vec3(0, 10000, 0), vec3(200, 300, 1400), this);
    game->addGameObject(train);
}

TrainGenerator::~TrainGenerator() { }

void TrainGenerator::generateTrains() {
    train->setActive(true);
    train->setPosition(position + vec3(2000, 0, 0));

    canGenerate = false;
}

void TrainGenerator::update() {
    if (canGenerate) time += ofGetLastFrameTime();

    if (time > 3) {
        generateTrains();
        time = 0;
    }
}

void TrainGenerator::draw() {
    int width = ROAD_WIDTH / 11;
    ofDrawBox(position.x, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 2, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 4, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 6, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 8, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 10, position.y - 24, position.z, width, 1, 300);
}