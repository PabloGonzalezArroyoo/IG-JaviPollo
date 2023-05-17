#pragma once
#include "GameObject.h"
#include "Train.h"

class Train;
class TrainGenerator : public GameObject {
private:
	int maxPedestrians;
	double time;
	bool canGenerate;

	vec3 position;
	Train* train;

public:
	TrainGenerator(Game* g, vec3 pos);
	~TrainGenerator();

	void generateTrains();
	virtual void update();
	virtual void draw();

	inline void setGenerate() { canGenerate = true; }
};
