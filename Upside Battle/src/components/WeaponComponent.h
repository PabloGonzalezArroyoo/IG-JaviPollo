#pragma once

#include "../ecs/Component.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include "Transform.h"

class WeaponComponent : public Component {
private:
	ofxBox2dRect* blockBody;

public:
	// Id del componente
	constexpr static cmpId_type id = _WEAPON;

	virtual void initComponent();
	virtual void render();

	void shoot();
};

