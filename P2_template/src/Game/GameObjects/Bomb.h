#pragma once

#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Airplane;
class Bomb : public GameObject {
private:
	int speed = 6;

	ofxAssimpModelLoader model;
	bool active;

	Airplane* generator;

public:
	Bomb(Game* game, vec3 pos, vec3 dim, Airplane* pg = nullptr);
	~Bomb();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;

	void notifyGenerator();
	void deactivateBomb();

	inline void setActive(bool act) { active = act; }
	inline void setPosition(vec3 pos) { transform.setPosition(pos); }
};