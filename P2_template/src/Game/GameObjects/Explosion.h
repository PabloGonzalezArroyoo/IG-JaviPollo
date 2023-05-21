#pragma once

#include "GameObject.h"

#include "ofxAssimpModelLoader.h"

class Airplane;
class Explosion : public GameObject {
private:
	double timer;
	ofxAssimpModelLoader model;

	bool active;

	Airplane* generator;

public:
	Explosion(Game* game, vec3 pos, vec3 dim, Airplane* pg = nullptr);
	~Explosion();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;

	void notifyGenerator();
	void deactivateExplosion();

	inline void setActive(bool act) { active = act; }
	inline void setPosition(vec3 pos) { transform.setPosition(pos); }
};