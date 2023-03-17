#pragma once
#include "../ecs/Component.h"
#include "../ecs/Entity.h"
#include "Transform.h"
#include "BlockComponent.h"

class InputComponent : public Component{
private:
	Transform* tr;
	BlockComponent* rect;

public:
	static constexpr int id = _INPUT;

	virtual void initComponent();

	void handleInput(int key);
};

