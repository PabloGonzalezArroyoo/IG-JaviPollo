
#include "GameObjectGenerator.h"
#include "Game.h"
#include "Road.h"
#include "Wall.h"
#include "Goal.h"
#include "Coin.h"
#include "Pedestrian.h"
#include "Obstacle.h"
#include "Barrier.h"
#include "Player.h"
#include "Oil.h"
#include "Soil.h"
#include "Arch.h"
#include "Hole.h"
#include "Airplane.h"
#include "Crane.h"
#include "Powerup.h"
#include "TrainGenerator.h"
#include "Checkpoint.h"

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    
    // Carretera
    auto road = new Road(game, ROAD_POS, ROAD_DIMS);
    game->addGameObject(road);
    
    // Paredes
    auto wall_r = new Wall(game, vec3(-ROAD_WIDTH/2, ROAD_POS.y, ROAD_POS.z), WALL_DIMS);
    game->addGameObject(wall_r);

    wall_r = new Wall(game, vec3(-ROAD_WIDTH / 2, ROAD_POS.y, ROAD_POS.z - ROAD_LENGTH * 0.8), WALL_DIMS);
    game->addGameObject(wall_r);

    auto wall_l = new Wall(game, vec3(ROAD_WIDTH / 2, ROAD_POS.y, ROAD_POS.z), WALL_DIMS);
    game->addGameObject(wall_l);

    wall_l = new Wall(game, vec3(ROAD_WIDTH / 2, ROAD_POS.y, ROAD_POS.z - ROAD_LENGTH * 0.8), WALL_DIMS);
    game->addGameObject(wall_l);
    
    // Meta
    auto goal = new Goal(game, GOAL_POS, GOAL_DIMS);
    goal->isFixed = true;
    game->addGameObject(goal);    

    // Variables auxiliares
    int randomX = 0;
    int randomZ = 0;
    int randomFactor = 0;

    // Generación aleatoria
    for (int i = 0; i < 25; i++) {
        // Moneda
        generateRandoms(i, randomX, randomZ, randomFactor);
        auto coin = new Coin(game, vec3(randomX, -25, randomZ), COINS_DIMS);
        game->addGameObject(coin);

        int random = rand() % 12;
        GameObject* gObj;

        switch (random) {
            case 0:
                // Obstáculo
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Obstacle(game, vec3(randomX, -25, randomZ), OBSTACLES_DIMS);
                break;
            case 1:
                // Barrera
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Barrier(game, vec3(randomX, 100, randomZ), BARRIERS_DIMS);
                break;
            case 2:
                // Aceite
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Oil(game, vec3(randomX, -49, randomZ), OILS_DIMS);
                break;
            case 3:
                // Hole
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Hole(game, vec3(randomX, -49, randomZ), HOLES_DIMS);
                break;
            case 4: case 11:
                // Powerup
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Powerup(game, vec3(randomX, -25, randomZ), vec3(100, 50, 50));
                break;
            case 5:
                // Tierra
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Soil(game, vec3(randomX, -49, randomZ), SOILS_DIMS);
                break;
            case 6:
                // Arco
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Arch(game, vec3(randomX, 300 / 2 - 49, randomZ), ARCHS_DIMS);
                break;
            case 7:
                // Airplane
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Airplane(game, vec3(randomX, 400, randomZ), AIRPLANE_DIMS);
                break;
            case 8:
                // Crane
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new Crane(game, vec3(randomX, 100, randomZ), CRANES_DIMS);
                break;
            case 9:
                // Generador de peatones
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new PedestrianGenerator(game, vec3(ROAD_WIDTH / 2 - 100, -25, randomZ));
                break;
            case 10:
                // Generador de trenes
                generateRandoms(i, randomX, randomZ, randomFactor);
                gObj = new TrainGenerator(game, vec3(ROAD_WIDTH / 2 - 100, -25, randomZ));
                break;
        }
        game->addGameObject(gObj);
    }

    auto checkpoint = new Checkpoint(game, vec3(0, 0, ROAD_LENGTH / 2), vec3(ROAD_WIDTH, ROAD_WIDTH, 100));
    game->addGameObject(checkpoint);
}

// Genera numeros aleatorios para las posiciones de los objetos
void GameObjectGenerator::generateRandoms(int i, int& ranX, int& ranY, int& fact) {
    if (rand() % 2 == 0) fact = 1;
    else fact = -1;

    ranX = (rand() % (ROAD_WIDTH / 2 - 150)) * fact;
    ranY = ((ROAD_LENGTH / 26 * i) + rand() % 200 + 1);
}