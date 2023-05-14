
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

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    
    // Carretera
    auto road = new Road(game, ROAD_POS, ROAD_DIMS);
    game->addGameObject(road);

    /*ofImage circuito;
    circuito.load("circuito.png");

    int w = circuito.getWidth()/16;
    int h = circuito.getHeight()/16;
    circuito.resize(w, h); */   
    
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
    for (int i = 1; i < 9; i++) {
        // Moneda
        generateRandoms(i, randomX, randomZ, randomFactor);
        auto coin = new Coin(game, vec3(randomX, -25, randomZ), COINS_DIMS);
        game->addGameObject(coin);

        if (i % 2 == 0) {
            // Barrera
            generateRandoms(i, randomX, randomZ, randomFactor);
            auto barrier = new Barrier(game, vec3(randomX, 100, randomZ), BARRIERS_DIMS);
            game->addGameObject(barrier);
        }
        else if (i % 3 == 0) {
            // Aceite
            generateRandoms(i, randomX, randomZ, randomFactor);
            auto oil = new Oil(game, vec3(randomX, -49, randomZ), OILS_DIMS);
            game->addGameObject(oil);
        }
        else if (i % 5 == 0) {
            // Hole
            generateRandoms(i, randomX, randomZ, randomFactor);
            auto hole = new Hole(game, vec3(randomX, -49, randomZ), HOLES_DIMS);
            game->addGameObject(hole);
        }
        else {
            // Obstáculo
            generateRandoms(i, randomX, randomZ, randomFactor);
            auto obstacle = new Obstacle(game, vec3(randomX, -25, randomZ), OBSTACLES_DIMS);
            game->addGameObject(obstacle);
        }
    }

    // Tierra
    auto soil = new Soil(game, vec3(100, -49, 400), SOILS_DIMS);
    game->addGameObject(soil);

    // Arco
    auto arch = new Arch(game, vec3(100, 300 / 2 - 49, 200), ARCHS_DIMS);
    game->addGameObject(arch);

    // Airplane
    auto airplane = new Airplane(game, vec3(100, 400, 1600), AIRPLANE_DIMS);
    game->addGameObject(airplane);

    // Crane
    auto crane = new Crane(game, vec3(400, 100, 1600), CRANES_DIMS);
    game->addGameObject(crane);

    // Generador de peatones
    auto generator = new PedestrianGenerator(game, vec3(0));
    game->addGameObject(generator);
}

// Genera numeros aleatorios para las posiciones de los objetos
void GameObjectGenerator::generateRandoms(int i, int& ranX, int& ranY, int& fact) {
    if (rand() % 2 == 0) fact = 1;
    else fact = -1;

    ranX = (rand() % (ROAD_WIDTH / 2 - 150)) * fact;
    ranY = ((ROAD_LENGTH / 10 * i) + rand() % 200 + 1);
}