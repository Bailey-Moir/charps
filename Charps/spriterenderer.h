#pragma once
#include "component.h"
#include "shader.h"
#include <vector>
#include <array>

using namespace std;

namespace Charps {

	/**
	 * The Sprite Renderer of a Game Object. Controls how the Game Object is rendered.
	 */
	class SpriteRenderer : public Component {
	private:
		static const int _indicies[6];
		unsigned int	_VAO = 0,
						_verticesVBO = 0,
						_colorVBO = 0,
						_EBO = 0;
		bool _colorChanged = true;

		/**
		 * The color to render the Game Object at.
		 */
		float _color[3] = { 1,0,0 };

		array<float, 8> _lastVertices = {
			0,0,
			0,0,
			0,0,
			0,0
		};

	public:
		/**
		 * All the sprite renderers.
		 */
		static vector<SpriteRenderer*> renderers;

		/**
		 * Constructor.
		 * @param gameObject The parent Game Object.
		 * @param shader The shader used to render the Game Object.
		 */
		SpriteRenderer(GameObject& gameObject, Shader* shader);
		/**
		 * Deconstructor that undoes affected memory.
		 */
		~SpriteRenderer();

		/**
		 * The shader this sprite renderer uses for rendering.
		 */
		Shader* shader;

		inline float calculateColor(int n, double t) const;

		/**
		 * Render the object.
		 */
		void render();
		void update();

		// GETTERS & SETTERS
		/**
		 * Sets the given pointers to the color of the object.
		 * @paarm The red color channel.
		 * @param The green color channel.
		 * @param The blue color channel.
		 */
		void getColor(float* r, float* g, float* b) const;
		/**
		 * Sets the color to the given floats.
		 * @paarm The red color channel.
		 * @param The green color channel.
		 * @param The blue color channel.
		 */
		void setColor(const float r, const float g, const float b);
	};
}