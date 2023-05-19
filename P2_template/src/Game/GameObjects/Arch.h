#pragma once

#include "GameObject.h"

class Arch : public GameObject {
private:
	ofFbo fbo;
	ofTrueTypeFont font;
	double timer;
	int coinsNumber;

	vec3 position;
	vec3 dimensions;

public:
	Arch(Game* game, vec3 pos, vec3 dim);
	~Arch();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;

	void randomNumber();
};