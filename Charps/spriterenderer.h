#pragma once
#include "component.h"

namespace Charps {
	/**
	 * The Sprite Renderer of a Game Object. Controls how the Game Object is rendered.
	 */
	struct SpriteRenderer : public Component {
		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 */
		SpriteRenderer(GameObject& gameObject);

		/**
		 * The color to render the Game Object at.
		 */
		const double color[4] = { 0.8,1,1,1 };
	};
}