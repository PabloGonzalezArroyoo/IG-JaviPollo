#pragma once

#include "GameObject.h"

class Explosion : public GameObject {
private:
	double timer;

public:
	Explosion(Game* game, vec3 pos, vec3 dim);
	~Explosion();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;
};