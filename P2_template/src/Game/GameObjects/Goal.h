

#ifndef Goal_h
#define Goal_h
#include "GameObject.h"

class Goal : public GameObject{
    
    
public:
    Goal(Game *game, vec3 pos, vec3 dim);
    ~Goal();
    
    void draw() override;
    void drawDebug() override;
    void receiveCarCollision(Player *car) override;
    
};

#endif /* Goal_h */
