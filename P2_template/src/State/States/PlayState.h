#ifndef PlayState_h
#define PlayState_h

#include "State.h"
#include "Game.h"


class PlayState: public State{
private:
    ofSoundPlayer music;

public:
    PlayState(Game *game);
    
    ~PlayState(){};
    
    void update();
    void draw();
    void keyPressed(int key);

    void pauseMusic(bool pause);
        
};
#endif
