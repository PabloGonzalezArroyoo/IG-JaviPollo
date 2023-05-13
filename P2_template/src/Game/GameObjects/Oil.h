#pragma once

#include "GameObject.h"

class Oil : public GameObject {
private:
	ofPlanePrimitive plane;
	ofTexture texture;

public:
	Oil(Game* g, glm::vec3 p, glm::vec3 d);
	~Oil();

	virtual void draw();
	void receiveCarCollision(Player* car) override;
};