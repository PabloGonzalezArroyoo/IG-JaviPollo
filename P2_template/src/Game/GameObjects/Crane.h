#pragma once

#include "GameObject.h"
#include "Claw.h"

class Crane : public GameObject {
private:
    GameObject* sujecion;
    Claw* gancho;

public:
    Crane(Game* game, glm::vec3 pos, glm::vec3 dim);
    ~Crane();

    void update() override;
    void draw() override;
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(GameObject* bullet) override;
};