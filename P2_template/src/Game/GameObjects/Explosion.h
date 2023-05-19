#pragma once

#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Explosion : public GameObject {
private:
	double timer;

	ofxAssimpModelLoader model;

public:
	Explosion(Game* game, vec3 pos, vec3 dim);
	~Explosion();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;
};