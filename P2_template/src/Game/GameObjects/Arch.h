#pragma once

#include "GameObject.h"

// HACER LA TEXTURA ANIMADA

class Arch : public GameObject {
private:
	int coinsNumber;

public:
	Arch(Game* game, glm::vec3 pos, glm::vec3 dim);
	~Arch();

	virtual void update();
	virtual void draw();
	void receiveCarCollision(Player* car) override;
};