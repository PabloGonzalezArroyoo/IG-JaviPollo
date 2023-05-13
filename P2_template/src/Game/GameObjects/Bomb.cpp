#include "Bomb.h"
#include "Player.h"
#include "Game.h"

Bomb::Bomb(Game* game, glm::vec3 pos, glm::vec3 dim) : GameObject(game, pos, dim) {
    material.setEmissiveColor(ofColor::paleVioletRed);

}

Bomb::~Bomb() { }

void Bomb::receiveCarCollision(Player* car) {
    car->setToInitPos();
    this->kill();
}

void Bomb::update() {
    transform.move(transform.getYAxis() * -speed);

    if (transform.getPosition().y < 0) {
        this->kill();
        auto explosion = new Explosion(game, transform.getPosition(), glm::vec3(200));
        game->addGameObject(explosion);
    }
}

void Bomb::draw() {
    material.begin();
    {
        collider->draw();
    }
    material.end();
}