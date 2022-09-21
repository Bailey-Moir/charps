#pragma once
#include "vector2.hpp"
#include "component.h"

namespace Charps {
	/**
	 * The Transform of a Game Object. Controls position, size, and rotation.
	 */
	struct Transform : public Component {
		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 */
		Transform(GameObject& gameObject);

		Vector2<double> position, size/*, rotation*/;
		
		/**
		 * Moves the object delta units per second.
		 * @param delta The amount the object moves per second.
		 */
		void translate(Vector2<double> delta);

		void update();
	};
}