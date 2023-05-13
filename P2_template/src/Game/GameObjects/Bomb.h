#pragma once

#include "GameObject.h"
#include "Explosion.h"

class Bomb : public GameObject {
private:
	int speed = 2;

public:
	Bomb(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Bomb();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;
};