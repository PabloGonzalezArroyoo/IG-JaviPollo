#ifndef ResultState_h
#define ResultState_h

#include "State.h"
class Game;

class ResultState: public State{
public:
    ResultState(Game *game);
    
    ~ResultState();
    
    void update();
    void draw();
        
};

#endif /* ResultState_h */
