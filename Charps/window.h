#pragma once
#include "vector2.h"
#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

namespace Charps {
	class Window {
	private:
		/**
		 * The private variable that is referenced by the getter and setter.
		 */
		Vector2<int> _size = Vector2<int>(), _pos = Vector2<int>();
		
		/**
		 * The private variable that is referenced by the getter and setter.
		 */
		string _title;
	public:
		/**
		 * The constructor for the window.
		 * @param width The width of the new window.
		 * @param height The height of the new window.
		 * @param title The title of the window.
		 */
		Window(int width, int height, string title);

		/**
		 * Initializes (in a non-literal sense) the window.
		 */
		void init();

		/**
		 * Update the window. Should run every frame.
		 */
		void update();
		/**
		 * Render to the window. Should run every frame.
		 */
		void render();

		/**
		 * The GLFW window struct.
		 */
		GLFWwindow* windowGLFW;
		
		/**
		 * The colour of the window.
		 */
		float color[3] = {1, 0, 0};

		// GETTERS AND SETTERS

		/**
		 * Window size setter.
		 */
		void setSize(Vector2<int> v);
		/**
		 * Window size getter.
		 */
		Vector2<int> getSize();

		/**
		 * Window position setter.
		 */
		void setPosition(Vector2<int> v);
		/**
		 * Window position getter.
		 */
		Vector2<int> getPosition();

		/**
		 * Window title setter.
		 */
		void setTitle(string v);
		/**
		 * Window title getter.
		 */
		string getTitle();
	};
}
