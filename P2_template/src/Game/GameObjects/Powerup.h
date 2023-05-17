#pragma once

#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Powerup : public GameObject {
private:
	ofxAssimpModelLoader model;

public:
	Powerup(Game* g, vec3 p, vec3 d);
	~Powerup();

	virtual void draw();
	void receiveCarCollision(Player* car) override;
};
