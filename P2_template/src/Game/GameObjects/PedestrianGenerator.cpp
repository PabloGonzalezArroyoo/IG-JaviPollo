#include "PedestrianGenerator.h"
#include "Game.h"

PedestrianGenerator::PedestrianGenerator(Game* g, vec3 p) : GameObject(g, p), time(0), canGenerate(true),
    position(p) {
    pedestrian = new Pedestrian(game, vec3(0, 10000, 0), vec3(50, 150, 50), false, this);
    game->addGameObject(pedestrian);
}

PedestrianGenerator::~PedestrianGenerator() { }

void PedestrianGenerator::generatePedestrians() {
    pedestrian->setActive(true);
    pedestrian->setPosition(position);

    canGenerate = false;
}

void PedestrianGenerator::update() {
    if (canGenerate) time += ofGetLastFrameTime();

    if (time > 2.5) {
        generatePedestrians();
        time = 0;
    }
}

void PedestrianGenerator::draw() {
    int width = ROAD_WIDTH / 11;
    ofDrawBox(position.x, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 2, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 4, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 6, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 8, position.y - 24, position.z, width, 1, 300);
    ofDrawBox(position.x - width * 10, position.y - 24, position.z, width, 1, 300);
}