#pragma once

#include "GameObject.h"

class Checkpoint : public GameObject {
private:
	vec3 position;
	vec3 dimensions;

public:
	Checkpoint(Game* game, vec3 pos, vec3 dim);
	~Checkpoint();

	virtual void draw();
	void receiveCarCollision(Player* car) override;
};