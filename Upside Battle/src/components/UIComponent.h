#pragma once
#include "../ecs/Component.h"
#include "../components/Transform.h"

class UIComponent : public Component {
private:
	ofRectangle uiBox;
	ofTrueTypeFont uiPoints;
	Transform* tr;
	int player;
	int points;
	string pointsString;

public:
	// Id del componente
	constexpr static cmpId_type id = _UI;

	UIComponent(int p);

	virtual void initComponent();
	virtual void render();

	void updatePoints(int pts);
	int getPoints() { return points; }
};

