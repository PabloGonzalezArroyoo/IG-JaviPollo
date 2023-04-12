#pragma once
#include "../ecs/Manager.h"
#include "../ofApp.h"

// Para evitar la dependencia circular
class ofApp;
class GameState {
protected:
	// Referencia al manager que contengo y a Game
	Manager* mng;
	ofApp* app;

public:
	// Constructoras
	GameState() : app(nullptr), mng(nullptr) { }
	GameState(ofApp* a) : app(a) { }

	virtual ~GameState() {
		delete mng;
	}

	// Métodos esenciales
	inline virtual void update() {
		mng->update();
	}
	inline virtual void render() {
		mng->render();
	}
	inline virtual void refresh() {
		mng->refresh();
	}
	virtual void keyPressed(int key) { }
	virtual void keyReleased(int key) { }
};