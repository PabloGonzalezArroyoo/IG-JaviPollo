
#ifndef Person_h
#define Person_h

#include "GameObject.h"
#include "PedestrianGenerator.h"

#include "ofxAssimpModelLoader.h"

class PedestrianGenerator;

class Pedestrian : public GameObject{
    float speed = -5;
    bool bTurned;
    bool canTurn;
    bool active;

    PedestrianGenerator* generator;

public:
    Pedestrian(Game *game, glm::vec3 pos, glm::vec3 dim, bool turn, PedestrianGenerator* pg = nullptr);
    ~Pedestrian();
    
    void update() override;
    void draw() override;
    void receiveCarCollision(Player *car) override;
    void receiveBulletCollision(GameObject *bullet) override;

    void notifyGenerator();
    void deactivatePedestrian();
    
    void checkCollisions() override;
    void turn();
    ofxAssimpModelLoader model;

    inline bool getCanTurn() { return canTurn; }
    inline void setActive(bool act) { active = act; }
    inline void setPosition(vec3 pos) { transform.setPosition(pos); }
};


#endif /* Person_h */
