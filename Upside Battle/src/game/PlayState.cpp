#include "PlayState.h"
#include "PauseState.h"
#include "WinState.h"

// Constructora
PlayState::PlayState(ofApp* a) : GameState(a) {
	// Añadir el manager
	mng = new Manager();

	// Inicializar mundo
	box2d.init();
	box2d.createBounds(0, ofGetHeight() / 7, ofGetWidth(), ofGetHeight() - ofGetHeight() / 7);
	box2d.setFPS(60.0);
	box2d.registerGrabbing();
	box2d.getWorld()->SetContactListener(new CollisionListener(mng));

	// Color del fondo
	ofSetBackgroundColor(19, 4, 68);

	// Mundo al manager
	mng->setWorld(&box2d);

	// Jugadores
	playerOne = mng->addEntity();
	playerTwo = mng->addEntity();

	// UI
	UIplayerOne = mng->addEntity(_grp_UI);
	UIplayerTwo = mng->addEntity(_grp_UI);

	music.load("../../resources/music.wav");
	music.setLoop(true);

	// Iniciar juego
	onGameStart();
}

void PlayState::update() {
	// Update del mundo y el manager
	box2d.update();
	mng->update();

	// Si algún jugador ha muerto
	if (!healthPlayerOne->isAlive() || !healthPlayerTwo->isAlive()) onRoundOver();

	// Si alguno ha ganado
	if (UIplayerOne->getComponent<UIComponent>()->getPoints() >= 25) onGameFinish(1);
	else if (UIplayerTwo->getComponent<UIComponent>()->getPoints() >= 25) onGameFinish(2);
}

// Input
void PlayState::keyPressed(int key) {
	if (key != 'p' && key != 'P') {
		inputOne->keyPressed(key);
		inputTwo->keyPressed(key);
	}
	else app->getGameStateMachine()->pushState(new PauseState(app));
}

// Input
void PlayState::keyReleased(int key) {
	inputOne->keyReleased(key);
	inputTwo->keyReleased(key);
}

void PlayState::onGameStart() {
	// JUGADOR 1
	// Entidad jugador
	playerOne->addComponent<BlockComponent>(&box2d, ofVec2f(BLOCK_DIMS + 10, ofGetHeight() / 2 + BLOCK_DIMS),
		BLOCK_DIMS, BLOCK_DIMS, 1);
	inputOne = playerOne->addComponent<InputComponent>(OF_KEY_LEFT, OF_KEY_RIGHT, OF_KEY_UP, OF_KEY_DOWN);
	// Interfaz
	UIplayerOne->addComponent<Transform>(ofVec2f(0, 0), ofGetWidth() / 2, ofGetHeight() / 7);
	UIplayerOne->addComponent<UIComponent>(1);
	// Arma
	weaponPlayerOne = mng->addEntity(_grp_WEAPONS);
	weaponPlayerOne->addComponent<PickupComponent>(&box2d, ofVec2f(ofGetWidth() - BLOCK_DIMS - 10, 150),
		WEAPON_DIMS, WEAPON_DIMS, 1);

	// JUGADOR 2
	// Entidad jugador
	playerTwo->addComponent<BlockComponent>(&box2d, ofVec2f(ofGetWidth() - BLOCK_DIMS - 10, ofGetHeight() / 2 + BLOCK_DIMS),
		BLOCK_DIMS, BLOCK_DIMS, 2);
	inputTwo = playerTwo->addComponent<InputComponent>('a', 'd', 'w', 's');
	// Interfaz
	UIplayerTwo->addComponent<Transform>(ofVec2f(ofGetWidth() / 2, 0), ofGetWidth() / 2, ofGetHeight() / 7);
	UIplayerTwo->addComponent<UIComponent>(2);
	// Arma
	weaponPlayerTwo = mng->addEntity(_grp_WEAPONS);
	weaponPlayerTwo->addComponent<PickupComponent>(&box2d, ofVec2f(BLOCK_DIMS + 10, ofGetHeight() - 40),
		WEAPON_DIMS, WEAPON_DIMS, 2);

	// Vida
	healthPlayerOne = playerOne->addComponent<HealthComponent>(MAX_LIFE, UIplayerTwo->getComponent<UIComponent>());
	healthPlayerTwo = playerTwo->addComponent<HealthComponent>(MAX_LIFE, UIplayerOne->getComponent<UIComponent>());

	// Crear mapa
	createMapOne();

	// Música
	music.play();
}

void PlayState::createMapOne() {
	// Mapa
	auto wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(150, 250), 125, 125);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(ofGetWidth() - 150, 250), 125, 125);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(150, ofGetHeight() - 150), 125, 125);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(ofGetWidth() - 150, ofGetHeight() - 150), 125, 125);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(ofGetWidth() / 2, 275), 30, 175);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(ofGetWidth() / 2, 600), 30, 175);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(250, ofGetHeight() / 2 + 50), 250, 30);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(ofGetWidth() - 250, ofGetHeight() / 2 + 50), 250, 30);
	
	// Reborde
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(0, ofGetHeight() / 7 + (ofGetHeight() - ofGetHeight() / 7) / 2),
		5, ofGetHeight() - ofGetHeight() / 7);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(ofGetWidth() / 2, ofGetHeight() / 7 + 1), ofGetWidth(), 5);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(ofGetWidth(), ofGetHeight() / 7 + (ofGetHeight() - ofGetHeight() / 7) / 2),
		5, ofGetHeight() - ofGetHeight() / 7);
	wall = mng->addEntity(_grp_MAP);
	wall->addComponent<WallComponent>(&box2d, ofVec2f(ofGetWidth() / 2, ofGetHeight()), ofGetWidth(), 5);
}

void PlayState::onRoundOver() {
	// Resetear posición de los jugadores
	auto body = playerOne->getComponent<BlockComponent>()->getBody();
	body->setVelocity(ofVec2f(0, 0));
	body->setPosition(ofVec2f(BLOCK_DIMS + 10, ofGetHeight() / 2 + BLOCK_DIMS));
	body = playerTwo->getComponent<BlockComponent>()->getBody();
	body->setVelocity(ofVec2f(0, 0));
	body->setPosition(ofVec2f(ofGetWidth() - BLOCK_DIMS - 10, ofGetHeight() / 2 + BLOCK_DIMS));

	// Quitar key de disparo y componente de arma
	inputOne->resetShootKey();
	inputTwo->resetShootKey();
	playerOne->removeComponent<WeaponComponent>();
	playerTwo->removeComponent<WeaponComponent>();

	// Resetear las armas
	mng->removeEntities(_grp_WEAPONS);
	weaponPlayerTwo = mng->addEntity(_grp_WEAPONS);
	weaponPlayerTwo->addComponent<PickupComponent>(&box2d, ofVec2f(BLOCK_DIMS + 10, ofGetHeight() - 40),
		WEAPON_DIMS, WEAPON_DIMS, 2);
	weaponPlayerOne = mng->addEntity(_grp_WEAPONS);
	weaponPlayerOne->addComponent<PickupComponent>(&box2d, ofVec2f(ofGetWidth() - BLOCK_DIMS - 10, 150),
		WEAPON_DIMS, WEAPON_DIMS, 1);

	// Revivir a los jugadores y quitar las balas del escenario
	healthPlayerOne->setAlive(true);
	healthPlayerTwo->setAlive(true);
	mng->removeEntities(_grp_BULLETS);
}

void PlayState::onGameFinish(int player) {
	// Parar música
	music.stop();
	// Lanzar estado de victoria
	app->getGameStateMachine()->changeState(new WinState(app, player));
}