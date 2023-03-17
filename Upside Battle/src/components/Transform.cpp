#include "Transform.h"

// Constructora vacía
Transform::Transform() : Component(), pos(ofVec2f()), vel(ofVec2f()), width(1), height(1), rotation(0) { }

// Constructora
Transform::Transform(ofVec2f _pos, ofVec2f _vel, int _width, int _height, float _rotation) :
	Component(), pos(_pos), vel(_vel), width(_width), height(_height), rotation(_rotation) { }

// Muve la nave sumando a la posición la velocidad del objeto
void Transform::update() {
	pos = pos + vel;
}