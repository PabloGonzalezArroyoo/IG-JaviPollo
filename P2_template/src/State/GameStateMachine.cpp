#include "GameStateMachine.h"

//Constructora con el primer estado del juego (el menu principal)
GameStateMachine::GameStateMachine(State* firstState) {
	pushState(firstState);
}

// Destructora - Borrar estados hasta que la pila est� vac�a
GameStateMachine::~GameStateMachine() {
	while (!states.empty()) popState();
}

// A�adir un nuevo estado a la pila
void GameStateMachine::pushState(State* state) {
	states.push(state);
}

// Elimina el estado de la pila
void GameStateMachine::popState() {
	State* actState = states.top();
	states.pop();
	delete(actState);
}

// Borra todos los estados acumulados en la pila
void GameStateMachine::discardStates() {
	while (!states.empty()) popState();
}

// Cambia estados de forma que borra el anterior y a�ade uno nuevo
void GameStateMachine::changeState(State* state) {
	popState();
	pushState(state);
}