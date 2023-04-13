#pragma once
#include "../ecs/Component.h"
#include "../ecs/Entity.h"
#include "BlockComponent.h"
#include "WeaponComponent.h"

class InputComponent : public Component{
private:
	Transform* tr;
	BlockComponent* rect;
	WeaponComponent* weapon;
	ofSoundPlayer sound;

	int keyIds[5];
	bool keys[5];

public:
	static constexpr int id = _INPUT;

	InputComponent(int keyLeft, int keyRight, int keyUp, int keyDown);

	virtual void initComponent();
	virtual void update();

	void keyPressed(int key);
	void keyReleased(int key);

	inline void setShootKey(int shoot, WeaponComponent* wp) { weapon = wp; keyIds[4] = shoot; }
	inline void resetShootKey() { keyIds[4] = INT64_MAX; keys[4] = false; }
};

