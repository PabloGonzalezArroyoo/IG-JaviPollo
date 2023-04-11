#pragma once
#include "b2Contact.h"
#include "../b2WorldCallbacks.h"
#include "Entity.h"
#include "../components/InputComponent.h"
#include "../components/BulletComponent.h"
#include "../components/PickupComponent.h"
#include "../ecs/Manager.h"

class CollisionListener : public b2ContactListener {
private:
	Manager* mng;

public:
	CollisionListener(Manager* manager) {
		mng = manager;
	}

	// Se llama al iniciarse una colisión
	virtual void BeginContact(b2Contact* contact) {
		b2Fixture* fixture1 = contact->GetFixtureA();
		b2Fixture* fixture2 = contact->GetFixtureB();
		b2Body* body1 = fixture1->GetBody();
		b2Body* body2 = fixture2->GetBody();

		// Coger datos del cuerpo
		Entity* ent1 = (Entity*) body1->GetUserData();
		Entity* ent2 = (Entity*) body2->GetUserData();

		// SI AMBAS ENTIDADES EXISTEN, HACER LO QUE CORRESPONDA
		if (ent1 != nullptr && ent2 != nullptr && ent1->isAlive() && ent2->isAlive()) {
			if (fixture1->IsSensor() || fixture2->IsSensor()) return;
			// COLISIÓN JUGADOR-ARMA
			if (ent1->hasComponent<InputComponent>() && ent2->hasComponent<PickupComponent>()) {
				auto blComp = ent1->getComponent<BlockComponent>();
				auto pkComp = ent2->getComponent<PickupComponent>();
				if (blComp->getPlayer() == pkComp->getPlayerPick()) {
					auto wpComp = ent1->addComponent<WeaponComponent>();
					if (pkComp->getPlayerPick() == 1) ent1->getComponent<InputComponent>()->setShootKey('l', wpComp);
					else ent1->getComponent<InputComponent>()->setShootKey('z', wpComp);
					ent2->setAlive(false);
				}
				return;
			}
			// COLISIÓN JUGADOR-BALA
			if ((ent1->hasComponent<InputComponent>() && ent2->hasComponent<BulletComponent>())) {
				auto health = ent1->getComponent<HealthComponent>();
				auto blComp = ent1->getComponent<BlockComponent>();
				auto bulletComp = ent2->getComponent<BulletComponent>();
				if (blComp->getPlayer() != bulletComp->getPlayer()) {
					health->receiveDamage(1);
				}
				ent2->setAlive(false);
				return;
			}
			if (ent1->hasComponent<BulletComponent>() && ent2->hasComponent<InputComponent>()) {
				auto health = ent2->getComponent<HealthComponent>();
				auto blComp = ent2->getComponent<BlockComponent>();
				auto bulletComp = ent1->getComponent<BulletComponent>();
				if (blComp->getPlayer() != bulletComp->getPlayer()) {
					health->receiveDamage(1);
				}
				ent1->setAlive(false);
				return;
			}
		}
	}
};