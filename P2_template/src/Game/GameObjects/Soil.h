#pragma once

#include "GameObject.h"

class Soil : public GameObject {
private:
	ofPlanePrimitive plane;

public:
	Soil(Game* g, glm::vec3 p, glm::vec3 d);
	~Soil();

	virtual void draw();
	void receiveCarCollision(Player* car) override;
};