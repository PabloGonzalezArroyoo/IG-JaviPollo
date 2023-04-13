#pragma once
#include "../ecs/Component.h"
class BulletComponent : public Component {
private:
	int playerBullet;
	ofxBox2dCircle* body;
	double time;

public:
	// Id del componente
	static constexpr cmpId_type id = _BULLET;

	BulletComponent(ofxBox2d* b2dworld, ofVec2f pos, ofVec2f vel, int playerBullet);
	~BulletComponent();

	virtual void update();
	virtual void render();
	virtual void initComponent();

	inline int getPlayer() { return playerBullet; }
};

