#include "rigidbody.h"
#include "gameobject.h"
#include "window.h"
#include "GLFW.h"

using namespace Charps;

RigidBody::RigidBody(GameObject& gameObject, double mass) : Component(gameObject, typeid(RigidBody)) {
	this->mass = mass;
}

void RigidBody::update() {
	#define dt (gameObject.window.time.deltaTime)
	#define f (force)
	#define m (mass)
	#define v (velocity)
	#define g (gravity)
	#define pos (gameObject.transform.position)

	if (g) f.y += m * g;

	v += f/m * dt;
	pos += v * dt;

	f = Vector2<double>(0);
}