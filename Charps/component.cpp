#include "component.h"
#include "gameobject.h"

using namespace Charps;

Component::Component(GameObject& gameObject) : gameObject(gameObject) {
	gameObject.addComponent(this);
	targetClass = this;
}