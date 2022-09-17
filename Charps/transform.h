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
	};
}