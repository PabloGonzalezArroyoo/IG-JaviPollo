#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"
#include "GameStateMachine.h"

class Player;

class Game : public StateMachine{
    ofEasyCam cam;
    Player *player;
    GameObjectContainer *gameObjects = nullptr;
    GameObjectGenerator *generator  = nullptr;
    bool bDebug;

    bool win;
    double timer;
    
    ofSoundPlayer scream;

    GameStateMachine* gsm;
    
public:    
    Game();
    ~Game();
    void init();
    void update();
    void draw();
    void toggleDebug();
    void playerWins();
    
    Player *getPlayer();
    vector<GameObject *> getCollisions(GameObject *gameObject);
    void addGameObject(GameObject *gameobject);
    
    float getEllapsedTime();
    void doScream();

    inline GameStateMachine* getGameStateMachine() { return gsm; }
    
};
#endif
