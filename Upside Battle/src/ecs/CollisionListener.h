#pragma once
#include "b2Contact.h"
#include "../b2WorldCallbacks.h"
#include "Entity.h"
#include "../components/InputComponent.h"
#include "../components/BulletComponent.h"

class CollisionListener : public b2ContactListener {
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
			if (ent1->hasComponent<InputComponent>() && ent2->hasComponent<BulletComponent>()) {
				
			}
		}
	}
};