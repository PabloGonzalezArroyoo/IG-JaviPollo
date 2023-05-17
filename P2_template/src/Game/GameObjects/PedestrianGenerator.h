#pragma once
#include "GameObject.h"
#include "Pedestrian.h"

class PedestrianGenerator : public GameObject {
private:
	int maxPedestrians;
	double time;
	bool canGenerate;

	vec3 position;
	Pedestrian* pedestrian;

public:
	PedestrianGenerator(Game* g, vec3 pos);
	~PedestrianGenerator();

	void generatePedestrians();
	virtual void update();
	virtual void draw();

	inline void setGenerate() { canGenerate = true; }
};