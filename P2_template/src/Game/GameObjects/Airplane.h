#pragma once

#include "GameObject.h"
#include "Bomb.h"

#include "ofxAssimpModelLoader.h"

class Airplane : public GameObject {
private:
	double timer;

	float speed = -5;
	bool bTurned;

	ofxAssimpModelLoader model;

public:
	Airplane(Game* game, vec3 pos, vec3 dim);
	~Airplane();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;
	void turn();
};