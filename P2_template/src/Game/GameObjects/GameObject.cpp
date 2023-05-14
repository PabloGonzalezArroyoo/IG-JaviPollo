

#include "GameObject.h"

GameObject::GameObject(Game *game, vec3 pos): game(game){
    init(pos);
}

GameObject::GameObject(Game *game, vec3 pos, vec3 dim): game(game){
    init(pos);
    collider->set(dim.x, dim.y, dim.z);
}

void GameObject::init(vec3 pos){
    collider = new BoxCollider(this);
    collider->setParent(transform);
    
    transform.setPosition(pos);
    bAlive = true;
}

GameObject::~GameObject(){
    delete collider;
}

bool GameObject::isAlive(){
    return bAlive;
}

void GameObject::drawDebug(){
    collider->drawDebug();
}
