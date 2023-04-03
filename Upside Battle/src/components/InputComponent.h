#pragma once
#include "../ecs/Component.h"
#include "../ecs/Entity.h"
#include "Transform.h"
#include "BlockComponent.h"

class InputComponent : public Component{
private:
	Transform* tr;
	BlockComponent* rect;

	int keyIds[4];
	bool keys[4];

public:
	static constexpr int id = _INPUT;

	InputComponent(int keyLeft, int keyRight, int keyUp, int keyDown);

	virtual void initComponent();
	virtual void update();

	void keyPressed(int key);
	void keyReleased(int key);
};

