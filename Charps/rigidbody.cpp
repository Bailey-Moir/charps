#include "rigidbody.h"
#include "gameobject.h"
#include "window.h"
#include "GLFW.h"

using namespace Charps;

RigidBody::RigidBody(GameObject& gameObject, double mass) : Component(gameObject, typeid(RigidBody)) {
	this->mass = mass;
}

void RigidBody::update() {
	auto drag = velocity*velocity*0.645*gameObject.transform.size.x*1;

	velocity += (editingForce + drag + Vector2<double>(0, gravity)) * gameObject.window.time.deltaTime / mass;
	gameObject.transform.translate(velocity*4);
}