#include "Transform.h"

// Constructora vacía
Transform::Transform() : Component(), pos(ofVec2f()), vel(ofVec2f()), width(1), height(1), rotation(0) { }

// Constructora
Transform::Transform(ofVec2f _pos, int _width, int _height, ofVec2f _vel, float _rotation) :
	Component(), pos(_pos), vel(_vel), width(_width), height(_height), rotation(_rotation) { }