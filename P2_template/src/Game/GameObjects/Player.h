#ifndef Player_h
#define Player_h

#include "ofMain.h"
#include "GameObject.h"
#include "ofxAssimpModelLoader.h"
class Game;

// TODO add speed settings
#define MAX_SPEED 100

class Player : public GameObject{
    

    ofxAssimpModelLoader model;

    vec3 iniPos;

    ofLight faro;
    float speed;
    bool bLight;
    vec3 prevPos;
    int coins;

    bool oiled;
    double oilTime;
    int auxFactor;
    double turnTime;

    bool soiled;

public:
    
    Player(Game *game);
    ~Player();
    
    void init();
    void update() override;
    void draw() override;
    void drawDebug() override;
    void checkCollisions() override;
    float getSpeed();
    
    void steerLeft();
    void steerRight();
    void accelerate();
    void toggleLight();
    void shoot();
    void brake();
    void stop();
    void addCoins(int n = 1);
    int getCoins();

    void oilMovement();
    inline void setOiled() { oiled = true; }
    inline bool isOiled() { return oiled; }

    inline void setSoiled() { soiled = true; }

    inline void setCoins(int x) { coins = x; }
    
    inline void setToInitPos() { 
        collider->setPosition(iniPos); 
        transform.setPosition(iniPos);
        speed = 0;
    }

    void boost(float value);
};

#endif 
