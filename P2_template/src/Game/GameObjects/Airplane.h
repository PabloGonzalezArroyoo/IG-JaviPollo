#pragma once

#include "GameObject.h"
#include "Bomb.h"

class Airplane : public GameObject {
private:
	double timer;

	float speed = -5;
	bool bTurned;

public:
	Airplane(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Airplane();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;
	void turn();
};