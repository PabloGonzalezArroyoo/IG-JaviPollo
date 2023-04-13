#pragma once
#include "../ecs/Component.h"

class WallComponent : public Component {
private:
	ofxBox2dRect* body;

public:
	// Id del componente
	static constexpr cmpId_type id = _BLOCK;

	// Constructora y destructora
	WallComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h);
	~WallComponent();

	// Métodos virtuales
	virtual void render();
};