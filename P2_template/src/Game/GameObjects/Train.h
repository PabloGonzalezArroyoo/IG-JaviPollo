
#ifndef Person_h
#define Person_h

#include "GameObject.h"
#include "TrainGenerator.h"

#include "ofxAssimpModelLoader.h"

class TrainGenerator;

class Train : public GameObject {
    float speed = -5;
    bool canTurn;
    bool active;

    TrainGenerator* generator;
    int life;

public:
    Train(Game* game, vec3 pos, vec3 dim, TrainGenerator* pg = nullptr);
    ~Train();

    void update() override;
    void draw() override;
    void receiveCarCollision(Player* car) override;
    void receiveBulletCollision(GameObject* bullet) override;

    void notifyGenerator();
    void deactivateTrain();

    ofxAssimpModelLoader model;

    inline void setActive(bool act) { active = act; }
    inline void setPosition(vec3 pos) { transform.setPosition(pos); }
};


#endif /* Person_h */
