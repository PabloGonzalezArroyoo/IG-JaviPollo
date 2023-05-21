#ifndef ResultState_h
#define ResultState_h

#include "State.h"
class Game;

class ResultState: public State{
private:
    // Textos
	string titleTxt;
	string startTxt;
	string timerTxt;
	string pointsTxt;

    ofTrueTypeFont title;
    ofTrueTypeFont titleShadow;
    ofTrueTypeFont points;
    ofTrueTypeFont time;
    ofTrueTypeFont pressStart;

public:
    ResultState(Game *game);
    
    ~ResultState();
    
    virtual void update();
    virtual void draw();
    virtual void keyPressed(int key);
};

#endif /* ResultState_h */
