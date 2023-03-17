#pragma once
#include "../ecs/Component.h"

class Transform : public Component {
private:
	// Variables de mi posicion, velocidad, dimensiones y rotacion
	ofVec2f pos;
	ofVec2f vel;
	int width;
	int height;
	float rotation;

public:
	// Id del componente
	constexpr static cmpId_type id = _TRANSFORM;

	// Constructoras
	Transform();
	Transform(ofVec2f _pos, int _width, int _height, ofVec2f _vel = ofVec2f(), float _rotation = 0);

	// Movimiento
	virtual void update();

	// Setters
	inline void setPosition(ofVec2f _pos) { pos = _pos; };
	inline void setVelocity(ofVec2f _vel) { vel = _vel; };
	inline void setRotation(float _rotation) { rotation = _rotation; }
	inline void setWidth(int _width) { width = _width; }
	inline void setHeight(int _height) { height = _height; }

	// Getters
	inline ofVec2f getPosition() { return pos; };
	inline ofVec2f getVelocity() { return vel; };
	inline float getRotation() { return rotation; }
	inline int getWidth() { return width; }
	inline int getHeight() { return height; }
};