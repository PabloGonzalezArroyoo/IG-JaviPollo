#pragma once

using namespace glm;
using namespace std;

// ROAD
const int ROAD_WIDTH = 2000;
const int ROAD_LENGTH = 10000;
const vec3 ROAD_POS = vec3(0, -50.1, ROAD_LENGTH / 2 - 1000);
const vec3 ROAD_DIMS = vec3(ROAD_WIDTH, 0, ROAD_LENGTH);

// WALLS
const int WALL_SIZE = 100;
const vec3 WALL_DIMS = vec3(WALL_SIZE, WALL_SIZE, ROAD_LENGTH);

// GOAL
const vec3 GOAL_POS = vec3(0, ROAD_POS.y, ROAD_POS.z + ROAD_LENGTH / 2);
const vec3 GOAL_DIMS = vec3(ROAD_WIDTH, 100, 100);

// OBSTACLES
const vec3 OBSTACLES_DIMS = vec3(100, 100, 100);

// COINS
const vec3 COINS_DIMS = vec3(50);

// BARRIER
const vec3 BARRIERS_DIMS = vec3(300, 200, 100);

// OIL
const vec3 OILS_DIMS = vec3(300, 0, 300);

// SOIL
const vec3 SOILS_DIMS = vec3(300, 0, 300);

// ARCH
const vec3 ARCHS_DIMS = vec3(400, 300, 50);

// HOLE
const vec3 HOLES_DIMS = vec3(400, 0, 200);

// AIRPLANE
const vec3 AIRPLANE_DIMS = vec3(300, 100, 200);
const vec3 BOMBS_DIMS = vec3(60);
const vec3 EXPLOSIONS_DIMS = vec3(200);

// CRANE
const vec3 CRANES_DIMS = vec3(100, 600, 100);

// TRAIN
const int TRAIN_MAX_LIFE = 3;