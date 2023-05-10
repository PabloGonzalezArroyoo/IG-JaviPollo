#pragma once
#include "GameObject.h"
#include "Pedestrian.h"

class PedestrianGenerator : public GameObject {
private:
	int maxPedestrians;
	double time;
	bool canGenerate;

public:
	PedestrianGenerator(Game* g, glm::vec3 pos);
	~PedestrianGenerator();

	void generatePedestrians();
	virtual void update();
	virtual void draw() {};

	inline void setGenerate() { canGenerate = true; }
};