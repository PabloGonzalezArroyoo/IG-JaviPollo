#include "ColliderComponent.h"
#include "../ecs/Manager.h"
#include "../utils/Collisions.h"

void ColliderComponent::addCollisionGroup(grpId id) {
	type.push_back(id);
}

void ColliderComponent::update() {
	hasCollided();
}

void ColliderComponent::addFunction(CallBackCol function) {
	functions.push_back(function);
}

void ColliderComponent::hasCollided() {
	//Sacamos todos los par�metros del transform propio
	Transform* tr = myObj->getComponent<Transform>();
	ofVec2f& pos1 = tr->getPosition();
	float width1 = tr->getWidth();
	float height1 = tr->getHeight();

	for (int i = 0; i < type.size(); i++) {
		vector<Entity*> others = myMng->getEntities(type[i]);
		//Por cada gameObject dentro del grupo correspondiente sacamos los par�metros de su transform
		for (Entity* other : others) {
			Transform* otherTr = other->getComponent<Transform>();
			ofVec2f& pos2 = otherTr->getPosition();
			float width2 = otherTr->getWidth();
			float height2 = otherTr->getHeight();

			//Se comprueba si colisionan utilizando los par�metros previamente obtenidos
			if (Collisions::collides(pos1, width1, height1, pos2, width2, height2))
			{
				// Si colisiona, realiza la funci�n
				for (CallBackCol function : functions) function(other);
			}
		}
	}
}