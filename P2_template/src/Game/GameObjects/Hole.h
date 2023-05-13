#pragma once

#include "GameObject.h"

class Hole : public GameObject {
private:
	ofPlanePrimitive plane;

public:
	Hole(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Hole();

	virtual void draw();
	void receiveCarCollision(Player* car) override;
};
