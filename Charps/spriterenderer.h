#pragma once
#include "component.h"
#include "shader.h"

namespace Charps {
	/**
	 * The Sprite Renderer of a Game Object. Controls how the Game Object is rendered.
	 */
	class SpriteRenderer : public Component {
		Shader shader;

	public:
		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 */
		SpriteRenderer(GameObject& gameObject);

		/**
		 * Render the object.
		 */
		void render();

		void update();

		/**
		 * The color to render the Game Object at.
		 */
		const double color[4] = { 0.8,1,1,1 };
	};
}