#pragma once
#include "vector2.hpp"
#include <vector>
#include <iostream>
#include "GLFW.h"
#include "input.h"
#include "time.h"

namespace Charps {
	/**
	 * Manages the game window itself.
	 */
	class Window {
	private:		
		/**
		 * The private variable that is referenced by the getter and setter.
		 */
		std::string _title;

	public:
		/**
		 * The constructor for the window.
		 * @param width The width of the new window.
		 * @param height The height of the new window.
		 * @param title The title of the window.
		 */
		Window(const unsigned int width, const unsigned int height, std::string title);

		/**
		 * The monitor the window is on.
		 */
		GLFWmonitor* monitor;

		/**
		 * The input manager of the window.
		 */
		Input input;

		/**
		 * The time manager of the window.
		 */
		Time time;

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
		float color[3] = {0, 0, 0};

		// GETTERS AND SETTERS

		/**
		 * Window title setter.
		 */
		void setTitle(const std::string v);
		/**
		 * Window title getter.
		 */
		std::string getTitle();
	};
}
