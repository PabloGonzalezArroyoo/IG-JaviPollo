#ifndef Game_h
#define Game_h

#include "ofMain.h"
#include "StateMachine.h"
#include "GameObjectContainer.h"
#include "GameObjectGenerator.h"
#include "GameStateMachine.h"

enum SOUNDS {
    COIN, EXPLOSION, HOLE, OIL, POWERUP, SHOOT, SOIL, ARCH, TRAIN
};

enum MUSICS {
    MENU, PLAYSATE, PAUSE, RESULTS
};

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

    ofTrueTypeFont speed;
    ofTrueTypeFont coins;
    ofTrueTypeFont timerF;

    vector<ofSoundPlayer> sounds;
    vector<ofSoundPlayer> musics;

    int points;
    
public:    
    Game();
    ~Game();
    void init();
    void update();
    void draw();
    void toggleDebug();
    void playerWins(bool w);

    void drawHUD();
    string twoDecimalFloatString(float f);
    
    Player *getPlayer();
    vector<GameObject *> getCollisions(GameObject *gameObject);
    void addGameObject(GameObject *gameobject);
    
    inline int getPoints() { return points; }
    inline void addPoints(int n) { points += n; }
    
    float getEllapsedTime();
    void doScream();

    inline GameStateMachine* getGameStateMachine() { return gsm; }
    
    // Sonidos y música
    inline void playSound(int s) {
        if (s == SHOOT) sounds[s].play();
        else if (!sounds[s].isPlaying()) sounds[s].play();
    }
    inline void playMusic(int m) { musics[m].play(); }
    inline void stopMusic(int m) { musics[m].stop(); }
    inline void pauseMusic(int m, bool b) { musics[m].setPaused(b); }
};
#endif
