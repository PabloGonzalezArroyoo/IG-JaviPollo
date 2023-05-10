#pragma once

#include "GameObject.h"

class Barrier : public GameObject {
private:
    int factor;
    int initialYPos;

public:

    Barrier(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Barrier();

    void draw() override;
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(GameObject* bullet) override;
    
    void update() override;
};