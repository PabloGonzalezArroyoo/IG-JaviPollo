#include "Collisions.h"

bool Collisions::collides(ofVec2f o1Pos, float o1Width, float o1Height, ofVec2f o2Pos, float o2Width, float o2Height) {
	// o1 completely to the left of o2, or vice versa
	if (o1Pos.x + o1Width < o2Pos.x
			|| o2Pos.x + o2Width < o1Pos.x) {
		return false;
	}

	// o1 completely to the top of o2, or vice versa
	if (o1Pos.y + o1Height < o2Pos.y
			|| o2Pos.y + o2Height < o1Pos.y) {
		return false;
	}

	return true;
}