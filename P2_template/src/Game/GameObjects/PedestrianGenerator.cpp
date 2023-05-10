#include "PedestrianGenerator.h"
#include "Game.h"

PedestrianGenerator::PedestrianGenerator(Game* g, glm::vec3 p) : GameObject(g, p), time(0), canGenerate(true) { }

PedestrianGenerator::~PedestrianGenerator() { }

void PedestrianGenerator::generatePedestrians() {
    auto pedestrian = new Pedestrian(game,
        glm::vec3(game->ROAD_WIDTH / 2 - 100, -25, 500), glm::vec3(50, 150, 50), false, this);

    game->addGameObject(pedestrian);

    canGenerate = false;
}

void PedestrianGenerator::update() {
    if (canGenerate) time += ofGetLastFrameTime();

    if (time > 3) {
        generatePedestrians();
        time = 0;
    }
}