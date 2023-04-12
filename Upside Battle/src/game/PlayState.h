#pragma once
#include "GameState.h"
#include "../ecs/Manager.h"
#include "../ecs/Entity.h"
#include "../components/InputComponent.h"
#include "../components/Transform.h"
#include "../components/BlockComponent.h"
#include "../components/UIComponent.h"
#include "../components/HealthComponent.h"
#include "../components/WeaponComponent.h"
#include "../ecs/CollisionListener.h"
#include "../components/WallComponent.h"

class PlayState : public GameState {
private:


public:
	// Constructora y destructora
	PlayState(ofApp* a);

	//Sobrecarga del metodo update
	virtual void update();
	virtual void render();
	virtual void refresh();

	void onGameStart();
	void onRoundOver();
	void onGameFinish(int player);
	void createMapOne();

	void keyPressed(int key);
	void keyReleased(int key);

	// Mundo (the box2d world)
	ofxBox2d box2d;

	// Jugador 1
	Entity* playerOne;
	InputComponent* inputOne;
	Entity* UIplayerOne;
	Entity* weaponPlayerOne;
	HealthComponent* healthPlayerOne;

	// Jugador 2
	Entity* playerTwo;
	InputComponent* inputTwo;
	Entity* UIplayerTwo;
	Entity* weaponPlayerTwo;
	HealthComponent* healthPlayerTwo;
};