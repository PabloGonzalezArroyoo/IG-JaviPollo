#ifndef GameObject_h
#define GameObject_h

#include "ofMain.h"
#include "iCollide.h"
#include "BoxCollider.h"
#include "Constants.h"

class Game;
class Player;

class GameObject: public iCollide{
    
protected:
    ofMaterial material;
    bool bAlive;
    Game *game;
    void init(vec3 pos);
    
public:
    ofNode transform;
    GameObject(Game *game, vec3 pos);
    GameObject(Game *game, vec3 pos,  vec3 dim);
    virtual ~GameObject();
    
    virtual void draw() { };
    virtual void drawDebug();
    virtual void update() {};
    virtual void checkCollisions(){};
    bool isAlive();
    void kill(){bAlive = false;};

    bool isFixed = false;
};

#endif 
