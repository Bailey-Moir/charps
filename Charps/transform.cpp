#include "transform.h"

using namespace Charps;

Transform::Transform(GameObject& gameObject) : Component(gameObject, typeid(Transform)) {
	size = Vector2<double>(1);
}

void Transform::update() {

}