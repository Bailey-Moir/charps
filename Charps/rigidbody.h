#pragma once
#include "component.h"
#include "vector2.hpp"

namespace Charps {
	/**
	 * The Rigidbody of a Game Object. Manages its phyiscs: forces, momentum, gravity, etc.
	 */
	struct RigidBody : public Component {
		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 * @param mass The initial mass of the Game Object.
		 */
		RigidBody(GameObject& gameObject, double mass);

		Vector2<double> force, velocity;
		double mass, gravity = -9.81;

		void update();
	};
}