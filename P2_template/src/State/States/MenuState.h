#ifndef MenuState_h
#define MenuState_h

#include "State.h"
#include "Game.h"

class MenuState: public State{
private:
    ofTrueTypeFont text;

public:
    MenuState(Game *game): State(game, "Menu State"){
    };
    
    ~MenuState(){};
    
    virtual void update();
    virtual void draw();     
    virtual void keyPressed(int key);
};
#endif 
