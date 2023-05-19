#include "Arch.h"
#include "Player.h"

Arch::Arch(Game* game, vec3 pos, vec3 dim) : GameObject(game, pos, dim), coinsNumber(0), timer(0) {
    material.setEmissiveColor(ofColor::cornflowerBlue);
    font.load("../../resources/fonts/starborn.ttf", 150);
    transform.rotate(-180, 0, 1, 0);

    position = pos;
    dimensions = dim;
    ofEnableNormalizedTexCoords();
    ofDisableArbTex();
    ofEnableAlphaBlending();
    fbo.allocate(400, 400);
}

Arch::~Arch() { }

void Arch::receiveCarCollision(Player* car) {
    car->addCoins(coinsNumber);
    this->kill();
}

void Arch::update() {
    randomNumber();
}

void Arch::draw() {
    fbo.getTexture().bind();
    {
        transform.transformGL();
        fbo.draw(-400 / 2, -300 / 2, 400, 300);
        material.begin();
        {
            // Palo izquierdo
            ofDrawBox(position.x - dimensions.x / 1.4, 0, 0,
                dimensions.x / 8, dimensions.y, dimensions.z);
            // Palo derecho
            ofDrawBox(position.x + dimensions.x / 4, 0, 0,
                dimensions.x / 8, dimensions.y, dimensions.z);
            // Palo central
            ofDrawBox(position.x - dimensions.x / 4.3, position.y + dimensions.y / 4.5, 0,
                dimensions.x + 40, dimensions.y / 8, dimensions.z);
        }
        material.end();
        transform.restoreTransformGL();
        //collider->draw();
    }
    fbo.getTexture().unbind();
}

void Arch::randomNumber() {
    timer += ofGetLastFrameTime();
    if (timer > 1) {
        coinsNumber = rand() % 30 + 1;
        timer = 0;

        fbo.begin();
        {
            ofClear(0); // Limpiar el fondo del FBO
            ofSetColor(255, 255, 255);
            string coinsText = to_string(coinsNumber);
            font.drawString(coinsText,
                dimensions.x / 2 - font.stringWidth(coinsText) / 2,
                dimensions.y / 2 + font.stringHeight(coinsText) / 2);
        }
        fbo.end();
    }
}