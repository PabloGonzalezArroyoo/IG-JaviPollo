#include "Transform.h"

// Constructora vacía
Transform::Transform() : Component(), pos(ofVec2f()), vel(ofVec2f()), width(1), height(1), rotation(0) { }

// Constructora
Transform::Transform(ofVec2f _pos, int _width, int _height, ofVec2f _vel, float _rotation) :
	Component(), pos(_pos), vel(_vel), width(_width), height(_height), rotation(_rotation) { }

// Muve la nave sumando a la posición la velocidad del objeto
void Transform::update() {
	/*ofVec2f newPos = pos + vel;
	if (newPos.x < ofGetWidth() - width && newPos.x > 0 && newPos.y < ofGetHeight() - height && newPos.y > 0) {
		pos = pos + vel;
	}*/
}