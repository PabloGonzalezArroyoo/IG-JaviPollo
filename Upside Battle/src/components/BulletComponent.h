#pragma once
#include "../ecs/Component.h"
class BulletComponent : public Component {
private:
	ofxBox2dCircle* body;

public:
	// Id del componente
	static constexpr cmpId_type id = _BULLET;

	BulletComponent();

	virtual void update();
	virtual void render();
};

