#pragma once
#include "Entity.h"
#include <vector>
#include <array>

using namespace std;

class Manager {
private:
	// Estructura de entidades -> array de vectores
	array<vector<Entity*>, maxGroupId> entsByGroup;
	array<Entity*, maxHandlerId> handlers;
	ofxBox2d* world;

public: 
	// Constructora y destructora
	Manager();
	virtual ~Manager();

	// M�todos esenciales
	void refresh();
	void update();
	void render();

	// Para a�adir una entidad al manager
	Entity* addEntity(grpId_type gId = _grp_GENERAL);

	// Getters
	const auto& getEntities(grpId_type gId = _grp_GENERAL) {
		return entsByGroup[gId];
	}

	// Elimina todas las entidades de un grupo deseado
	void removeEntities(grpId_type gId) {
		for (Entity* e : entsByGroup[gId]) {
			e->setAlive(false);
		}
	}

	inline Entity* getHandler(hdlrId_type hId) {
		return handlers[hId];
	}

	inline ofxBox2d* getWorld() {
		return world;
	}

	// Setter
	inline void setHandler(hdlrId_type hId, Entity* e) {
		handlers[hId] = e;
	}

	inline void setWorld(ofxBox2d* w) {
		world = w;
	}
};