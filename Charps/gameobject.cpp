#include "gameobject.h"
#include "window.h"

using namespace Charps;
using namespace std;

GameObject::GameObject() : transform(*this), window(*Window::context) {}

void GameObject::addComponent(Component* component) {
	components.push_back(component);
}
void Charps::GameObject::removeComponent(Component* component) {
	auto end = components.end();
	components.erase(remove(components.begin(), end, component), end);

}
