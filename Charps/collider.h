#pragma once
#include "component.h"
#include "vector2.hpp"
#include "rigidbody.h"

namespace Charps {
	/**
	 * The abstract class that represents any given collider component. Manages collision resolution, but not collision detection (that is the job of the extenders).
	 */
	class Collider : public Component {
	public:
		RigidBody* rb = NULL;

		/**
		 * Resolves a collision that has occured with another object.
		 * @param Furthest point of this object into the other.
		 * @param Furthest point of the other object into this.
		 */
		void resolveCollision(const Vector2<double>& A, const Vector2<double>& B, const Collider& obj);
	};
}