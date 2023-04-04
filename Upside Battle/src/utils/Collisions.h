#pragma once
#include "ofVec2f.h"

class Collisions {

private:

public:
	static bool collides(ofVec2f o1Pos, float o1Width, float o1Height, ofVec2f o2Pos, float o2Width, float o2Height);
};
