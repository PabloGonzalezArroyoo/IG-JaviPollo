#ifndef ResultState_h
#define ResultState_h

#include "State.h"
class Game;

class ResultState: public State{
public:
    ResultState(Game *game);
    
    ~ResultState();
    
    virtual void update();
    virtual void draw();
    virtual void keyPressed(int key);
};

#endif /* ResultState_h */
