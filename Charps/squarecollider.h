#pragma once
#include "collider.h"
#include "circlecollider.h"

namespace Charps {
	/**
	 * The component to add a square collider.
	 */
	class SquareCollider : public Collider {
	public:
		/**
		 * The distance from the middle to a side of the collider (assuming a normal relationship to the side).
		 */
		float radius;

		void checkCollision(SquareCollider col);
		void checkCollision(CircleCollider col);
	};
}