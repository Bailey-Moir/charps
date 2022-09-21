#pragma once
#include "component.h"
#include "shader.h"
#include <vector>

namespace Charps {
	/**
	 * The Sprite Renderer of a Game Object. Controls how the Game Object is rendered.
	 */
	struct SpriteRenderer : public Component {
		/**
		 * All the sprite renderers.
		 */
		static std::vector<SpriteRenderer*> renderers;

		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 */
		SpriteRenderer(GameObject& gameObject, Shader& shader);

		/**
		 * The shader this sprite renderer uses for rendering.
		 */
		Shader& shader;

		/**
		 * The color to render the Game Object at.
		 */
		float color[3] = { 1,0,0 };

		inline float calculateColor(int n, double t);

		/**
		 * Render the object.
		 */
		void render();

		void update();
	};
}