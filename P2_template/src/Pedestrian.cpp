

#include "Pedestrian.h"
#include "Player.h"
#include "Game.h"

Pedestrian::Pedestrian(Game *game, glm::vec3 pos, glm::vec3 dim, bool turn, PedestrianGenerator* pg): GameObject(game, pos, dim),
    canTurn(turn), generator(pg), active(false) {
    model.loadModel("../../resources/models/astroBoy_walk.dae");
    
    collider->move(0, dim.y/2 - 25, 0);
    model.setRotation(0, 180, 1, 0, 0);
    model.setPosition(0, -25, 0);
    model.setScale(0.25, 0.25, 0.25);
    model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
    model.playAllAnimations();
    
    transform.rotateDeg(90, 0, 1, 0);
    speed = 6;
    bTurned = false;
}
Pedestrian::~Pedestrian() { }

void Pedestrian::update() {
    if (active) {
        model.update();
        transform.move(transform.getZAxis() * -speed);
        bTurned = false;

        if (transform.getPosition().x <= -ROAD_WIDTH / 2) deactivatePedestrian();
    }
};
void Pedestrian::draw(){
    if (active) {
        transform.transformGL();
        model.drawFaces();
        transform.restoreTransformGL();
    }
};

void Pedestrian::deactivatePedestrian() {
    setPosition(vec3(0, 10000, 0));
    setActive(false);
    notifyGenerator();
}

void Pedestrian::receiveCarCollision(Player *car) {
    deactivatePedestrian();
    game->doScream();
};

void Pedestrian::receiveBulletCollision(GameObject *bullet) {
    bullet->kill();
    game->doScream();
    deactivatePedestrian();
    game->getPlayer()->addCoins(1000);
};

void Pedestrian::turn(){
    if(!bTurned){
        transform.rotateDeg(180, 0, 1, 0);
        transform.move(transform.getZAxis() * -speed);
        bTurned = true;
    }
}

void Pedestrian::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receivePedestrianCollision(this);
    }
}

void Pedestrian::notifyGenerator() {
    if (generator != nullptr) generator->setGenerate();
}
