#include "gameobject.h"

using namespace Charps;
using namespace std;

vector<Component*> Component::allComponents = vector<Component*>();

Component::Component(GameObject& gameObject, const type_info& id) : gameObject(gameObject), id(id) {
	gameObject.addComponent(this);
	allComponents.push_back(this);
}
Component::~Component() {
	gameObject.removeComponent(this);
	remove(allComponents.begin(), allComponents.end(), this);
}

void Component::update() {}
