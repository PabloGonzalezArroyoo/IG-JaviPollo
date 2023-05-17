
#include "Bullet.h"
#include "Game.h"

Bullet::Bullet(Game *game, ofNode otherTransform)
    :GameObject(game, otherTransform.getGlobalPosition(), vec3(20)), timer(0)
{
        transform.setGlobalOrientation(otherTransform.getGlobalOrientation());
    material.setEmissiveColor(ofColor::red);
}

Bullet::~Bullet(){}

void Bullet::update(){
    transform.move(transform.getZAxis() * 100);

    timer += ofGetLastFrameTime();
    if (timer > 1) { this->kill(); timer = 0; }
};

void Bullet::draw(){
    
    material.begin();
    {
        collider->draw();
    }
    material.end();
    
};

void Bullet::checkCollisions(){
    vector<GameObject*> collisions = game->getCollisions(this);
    for(auto c: collisions){
        c->receiveBulletCollision(this);
    }
}
