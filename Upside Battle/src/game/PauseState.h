#pragma once
#include "GameState.h"

class PauseState : public GameState {
private:

public:
	// Constructora
	PauseState();

	// Sobrecarga del metodo update
	virtual void update();
};