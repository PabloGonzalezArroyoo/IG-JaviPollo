#pragma once
#include "../ecs/Component.h"

class BlockComponent : public Component {
private:
	ofxBox2dRect* body;
	int player;

public:
	// Id del componente
	static constexpr cmpId_type id = _BLOCK;

	// Constructora y destructora
	BlockComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h, int p);
	~BlockComponent();

	// Métodos virtuales
	virtual void initComponent();
	virtual void render();
	virtual void update();

	// Mover el bloque
	void move(ofVec2f vel);

	// Getters
	inline ofxBox2dRect* getBody() { return body; }
	inline float getMagnitudedVelocity() { return sqrtf(powf(body->getVelocity().x, 2) + powf(body->getVelocity().y, 2)); }
	inline int getPlayer() { return player; }
};