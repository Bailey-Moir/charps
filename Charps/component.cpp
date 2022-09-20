#include "component.h"
#include "gameobject.h"

using namespace Charps;

Component::Component(GameObject& gameObject, const std::type_info& id) : gameObject(gameObject), id(id) {
	gameObject.addComponent(this);
}

void Component::update() {}
