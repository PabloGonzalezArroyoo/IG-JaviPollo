#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"

class MenuState: public State{
private:
	// Fuentes
	ofTrueTypeFont title;
	ofTrueTypeFont titleShadow;
	ofTrueTypeFont pressStart;

	// Textos
	string titleTxt;
	string startTxt;

	// Variables
	int alpha;
	int changeFactor;

public:
    MenuState(Game* game);
    
    ~MenuState(){};
    
    virtual void update();
    virtual void draw();     
    virtual void keyPressed(int key);
};
#endif 
