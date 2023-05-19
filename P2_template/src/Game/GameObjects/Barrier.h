#pragma once

#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Barrier : public GameObject {
private:
    int factor;
    int initialYPos;

    ofxAssimpModelLoader model;

public:

    Barrier(Game* game, vec3 pos, vec3 dim);
    ~Barrier();

    void draw() override;
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(GameObject* bullet) override;
    
    void update() override;
};