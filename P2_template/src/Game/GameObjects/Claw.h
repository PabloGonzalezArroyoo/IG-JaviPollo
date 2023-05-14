#pragma once

#include "GameObject.h"

class Claw : public GameObject {
private:
    int initYPos;
    int speed;
public:
    Claw(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Claw();

    void update() override;
    void draw() override;
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(GameObject* bullet) override;
};