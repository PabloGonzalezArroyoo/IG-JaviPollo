#pragma once

#include "State.h"
#include "Game.h"

class PauseState : public State {
public:
    PauseState(Game* game);

    ~PauseState() {};

    void update();
    void draw();
    void keyPressed(int key);
};