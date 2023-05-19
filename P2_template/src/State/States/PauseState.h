#pragma once

#include "State.h"
#include "Game.h"

class PauseState : public State {
private:
    // Textos
    ofTrueTypeFont pause;
    ofTrueTypeFont controls;
    string pressTxt;
    string pauseTxt;
    string controlsTxt;

public:
    PauseState(Game* game);
    ~PauseState() {};

    void update();
    void draw();
    void keyPressed(int key);
};