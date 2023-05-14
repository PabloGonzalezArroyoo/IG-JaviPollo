#pragma once

#include "GameObject.h"

class Hole : public GameObject {
private:
	ofPlanePrimitive plane;
	ofTexture texture;

public:
	Hole(Game* game, vec3 pos, vec3 dim);
	~Hole();

	virtual void draw();
	void receiveCarCollision(Player* car) override;
};
