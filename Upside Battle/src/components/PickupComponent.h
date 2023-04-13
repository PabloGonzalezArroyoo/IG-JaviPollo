#pragma once
#include "../ecs/Component.h"

class PickupComponent : public Component {
private:
	int playerPick;
	ofxBox2dRect* body;

public:
	// Id del componente
	static constexpr cmpId_type id = _BLOCK;

	PickupComponent(ofxBox2d* b2dworld, ofVec2f pos, float w, float h, int p);
	~PickupComponent();

	virtual void initComponent();

	virtual void update();
	virtual void render();

	inline int getPlayerPick() { return playerPick; }
};