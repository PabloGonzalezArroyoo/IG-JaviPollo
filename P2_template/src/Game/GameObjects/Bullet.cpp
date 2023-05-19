
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game *game, ofNode otherTransform)
    :GameObject(game, otherTransform.getGlobalPosition(), vec3(20)), timer(0)
{
        transform.setGlobalOrientation(otherTransform.getGlobalOrientation());
    material.setEmissiveColor(ofColor::red);
    model.loadModel("../../resources/models/bullet.fbx");
    model.setScale(0.1, 0.1, 0.1);
}

Bullet::~Bullet(){}

void Bullet::update(){
    transform.move(transform.getZAxis() * 100);

    timer += ofGetLastFrameTime();
    if (timer > 1) { this->kill(); timer = 0; }
};

void Bullet::draw(){
    transform.transformGL();
    model.drawFaces();
    transform.restoreTransformGL();
};

void Bullet::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveBulletCollision(this);
    }
}
