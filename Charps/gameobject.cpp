#include "gameobject.h"
#include "window.h"

using namespace Charps;

GameObject::GameObject(Window& window) : transform(*this), window(window) {}

void GameObject::addComponent(void* component) {
	components.push_back(component);
}
