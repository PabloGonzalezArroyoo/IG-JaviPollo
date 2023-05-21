#pragma once

#include "GameObject.h"
#include "Explosion.h"
#include "ofxAssimpModelLoader.h"

class Bomb : public GameObject {
private:
	int speed = 6;

	ofxAssimpModelLoader model;

public:
	Bomb(Game* game, vec3 pos, vec3 dim);
	~Bomb();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;
};