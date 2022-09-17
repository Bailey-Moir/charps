#pragma once

namespace Charps {
	/**
	 * Holds all the information needs to render an object.
	 */
	class TexturedModel {
	public:
		/**
		 * The GL texture ID.
		 */
		const int textureID;
		/**
		 * The GL Vertex Array Object ID
		 */
		const int vaoID;
		/**
		 * The amount of vertices in the model.
		 */
		const int vertexCount;

		/**
		 * Constructor.
		 * @param textureID The GL texture ID.
		 * @param vaoID The GL Vertex Array Object ID
		 * @param vertexCount The amount of vertices in the model.
		 */
		TexturedModel(const int textureID, const int vaoID, const int vertexCount);
	};
}