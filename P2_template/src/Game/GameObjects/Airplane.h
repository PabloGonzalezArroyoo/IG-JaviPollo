#pragma once

#include "GameObject.h"
#include "Bomb.h"
#include "Explosion.h"

#include "ofxAssimpModelLoader.h"

class Airplane : public GameObject {
private:
	double timer;

	float speed = -5;
	bool bTurned;
	bool canGenerate;

	Bomb* bomb;
	Explosion* explosion;
	ofxAssimpModelLoader model;

public:
	Airplane(Game* game, vec3 pos, vec3 dim);
	~Airplane();

	virtual void update();
	virtual void draw();
	void turn();

	void generateBombs();

	inline void setGenerate() { canGenerate = true; }
	void createExplosion(vec3 pos);
};