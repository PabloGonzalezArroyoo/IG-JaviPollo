#pragma once

#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Obstacle : public GameObject {
private:
    ofxAssimpModelLoader model;

public:
    Obstacle(Game* game, vec3 pos, vec3 dim);
    ~Obstacle();

    void draw() override;
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(GameObject* bullet) override;

};