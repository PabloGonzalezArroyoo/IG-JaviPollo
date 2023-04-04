#pragma once
#include "../ecs/Component.h"
#include "Transform.h"

class ColliderComponent :public Component {
private:
	Transform* tr;
	vector<grpId> type;
	vector<CallBackCol> functions;

public:
	static const int id = _COLLIDER;

	virtual void update();
	void hasCollided();
	void addFunction(CallBackCol function);
	void addCollisionGroup(grpId id);
};
