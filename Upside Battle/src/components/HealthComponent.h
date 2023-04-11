#pragma once

#include "../ecs/Component.h"
#include "Transform.h"
#include "UIComponent.h"

// Este componente sirve para manejar todos los eventos relacionados con la vida del objeto
// Como su muerte o su curaci�n
class HealthComponent : public Component {
private:
	int lifePoints;
	int maxLife;
	bool invincibility;
	float invTime;
	float time;

	bool alive;

	ofxBox2dRect* tr;
	vector<ofRectangle> lifesHUD;

	UIComponent* ui;

public:
	static const int id = _HEALTH;

	HealthComponent(int Maxlife, UIComponent* ui, bool invincibility = false);

	virtual void initComponent();
	
	// Delete del padre
	void receiveDamage(int damage);

	virtual void update();
	virtual void render();
	void die();

	// Devuelve el valor actual de la vida
	inline int getLife() { return lifePoints; }
	inline bool isAlive() { return alive; }
	inline void setAlive(bool a) { alive = a; }
};
