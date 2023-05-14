#include "Arch.h"
#include "Player.h"

Arch::Arch(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim), coinsNumber(0), timer(0) {
    material.setEmissiveColor(ofColor::cornflowerBlue);
    font.load("starborn.ttf", 300);
    transform.rotate(-180, 0, 1, 0);
    ofEnableNormalizedTexCoords();
    ofDisableArbTex();

    position = pos;
    dimensions = dim;

    fbo.allocate(ofGetWidth(), ofGetHeight());
}

Arch::~Arch() { }

void Arch::receiveCarCollision(Player* car) {
    car->addCoins(coinsNumber);
    this->kill();
}

void Arch::draw() {
    fbo.getTexture().bind();
    {
        transform.transformGL();
        renderNumber();
        material.begin();
        {
            // Palo izquierdo
            ofDrawBox(position.x - dimensions.x / 1.4, 0, 0,
                dimensions.x / 8, dimensions.y, dimensions.z);
            // Palo derecho
            ofDrawBox(position.x + dimensions.x / 4, 0, 0,
                dimensions.x / 8, dimensions.y, dimensions.z);
            // Palo central
            ofDrawBox(position.x - dimensions.x / 4.3, position.y + 50, 0,
                dimensions.x + 40, dimensions.y / 8, dimensions.z);
        }
        material.end();
        transform.restoreTransformGL();
        //collider->draw();
    }
    fbo.getTexture().unbind();
}

void Arch::renderNumber() {
    fbo.begin();

    ofClear(0); // Limpiar el fondo del FBO
    ofSetColor(255, 255, 255);
    timer += ofGetLastFrameTime();
    if (timer > 1) {
        coinsNumber = rand() % 30 + 1;
        timer = 0;
    }

    font.drawString(to_string(coinsNumber), 
        dimensions.x / 2 + font.stringWidth(to_string(coinsNumber)) / 4,
        dimensions.y / 2 + font.stringHeight(to_string(coinsNumber)) / 4);
    fbo.end();

    fbo.draw(-400/2, -300/2, 400, 300);
}