
#ifndef Bullet_h
#define Bullet_h

#include "GameObject.h"
#include "ofxAssimpModelLoader.h"

class Bullet : public GameObject{
private:
    double timer;

    ofxAssimpModelLoader model;

public:
    Bullet(Game *game, ofNode transform);
    ~Bullet();
    
    void update() override;
    void draw() override;
    void checkCollisions() override;
    
};
#endif /* Bullet_h */
