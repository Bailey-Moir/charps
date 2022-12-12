#include "gameobject.h"
#include "window.h"

using namespace Charps;

GameObject::GameObject() : transform(*this), window(*Window::context) {}

void GameObject::addComponent(Component* component) {
	components.push_back(component);
}