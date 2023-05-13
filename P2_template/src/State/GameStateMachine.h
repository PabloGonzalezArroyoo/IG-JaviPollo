#pragma once

#include <stack>
#include "State.h"
using namespace std;

class GameStateMachine
{
private:
	// Pila de estados
	stack<State*> states;

public:
	// Constructoras y destructora
	GameStateMachine() {};
	GameStateMachine(State* firstState);
	~GameStateMachine();

	// Métodos de gestión de estados
	State* currentState() { return states.top(); };
	void pushState(State* _state);
	void changeState(State* newState);
	void popState();
	void discardStates();
};