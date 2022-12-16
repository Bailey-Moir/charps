#pragma once
#include "collider.h"
#include "squarecollider.h"

namespace Charps {
	/**
	 * The component to add a circle collider.
	 */
	class CircleCollider : public Collider {
	public:
		/**
		 * The radius of the circle that makes up the collider.
		 */
		double radius;

		void checkCollision(const SquareCollider col);
		void checkCollision(const CircleCollider col);
	};
}