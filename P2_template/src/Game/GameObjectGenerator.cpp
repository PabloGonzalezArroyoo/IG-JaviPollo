
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

GameObjectGenerator::GameObjectGenerator(Game *game): game(game){}

void GameObjectGenerator::generateWorld(){
    int W = game->ROAD_WIDTH;
    int L = game->ROAD_LENGTH;
    
    glm::vec3 roadPos(0, -50.1, L/2 - 1000);
    auto road = new Road(game, roadPos, glm::vec3(W, 0, L));
    
    game->addGameObject(road);
//
    int wallSize = 100;

    ofImage circuito;
    circuito.load("circuito.png");

    int w = circuito.getWidth()/16;
    int h = circuito.getHeight()/16;
    circuito.resize(w, h);


//    for(int x = 0; x < w; x++){
//        for(int y = 0; y < h; y++){
//            if(circuito.getColor(x, y).a > 250){
//
//                auto wall = new Wall(game,
//                                glm::vec3(x*wallSize - 5000, roadPos.y, y*wallSize -2000),
//                                glm::vec3(wallSize*0.99));
//                game->addGameObject(wall);
//            }
//        }
//    }

    
//     WALL with parts
//    for(int l = 0; l < L; l += wallSize){
//        auto wall_r = new Wall(game,
//                        glm::vec3(-W/2, roadPos.y, l - 1000 + wallSize/2),
//                        glm::vec3(wallSize));
//
//        wall_r->isFixed = true;
//        game->addGameObject(wall_r);
//
//    }
    
    
    auto wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    wall_r = new Wall(game,
                    glm::vec3(-W/2, roadPos.y, roadPos.z - L * 0.8),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_r);

    
    auto wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);

    wall_l = new Wall(game,
                    glm::vec3(W/2, roadPos.y, roadPos.z - L * 0.8),
                           glm::vec3(wallSize, wallSize, L));
    game->addGameObject(wall_l);
//
    auto goal = new Goal(game,
                    glm::vec3(0, roadPos.y, roadPos.z + L/2),
                           glm::vec3(W, 100, 100));
    goal->isFixed = true;
    game->addGameObject(goal);    

    // Variables auxiliares
    int randomX = 0;
    int randomZ = 0;
    int randomFactor = 0;

    // Obstáculos y monedas
    for (int i = 1; i < 9; i++) {
        generateRandoms(i, randomX, randomZ, randomFactor);

        auto obstacle = new Obstacle(game, glm::vec3(randomX, -25, randomZ), glm::vec3(100, 150, 100));
        game->addGameObject(obstacle);

        generateRandoms(i, randomX, randomZ, randomFactor);

        auto coin = new Coin(game, glm::vec3(randomX, -25, randomZ), glm::vec3(50));
        game->addGameObject(coin);
    }

    // Barrera
    auto barrier = new Barrier(game, glm::vec3(0, 100, L/2), glm::vec3(300, 200, 100));
    game->addGameObject(barrier);

    // Aceite
    auto oil = new Oil(game, glm::vec3(-50, -49, 200), glm::vec3(50, 0, 50));
    game->addGameObject(oil);

    auto soil = new Soil(game, glm::vec3(100, -49, 400), glm::vec3(200, 0, 400));
    game->addGameObject(soil);

    // Generador de peatones
    auto generator = new PedestrianGenerator(game, glm::vec3(0));
    game->addGameObject(generator);
}

// Genera numeros aleatorios para las posiciones de los objetos
void GameObjectGenerator::generateRandoms(int i, int& ranX, int& ranY, int& fact) {
    if (rand() % 2 == 0) fact = 1;
    else fact = -1;

    ranX = (rand() % (game->ROAD_WIDTH / 2 - 150)) * fact;
    ranY = ((game->ROAD_LENGTH / 10 * i) + rand() % 200 + 1);
}