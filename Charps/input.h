#pragma once
#include <string>
#include <vector>
#include <GLFW/glfw3.h>
#include "vector2.h"

namespace Charps {
	// Forward declration
	class Window;
	
	/**
	 * Manages all input, e.g. mouse and keyboard usage.
	 */
	class Input {
	public:
		/**
		 * An input axis.
		 */
		class Axis {
		public:
			/**
			 * Constructor
			 * @param name The name of the axis, e.g. 'horizontal'
			 * @param keys An array of all the keys that affect the axis. The items in this array should come in pairs such that the first affects the axis positively and the second affects the array negatively.
			 * @param count The size of the previous array.
			 */
			Axis(std::string name, int* keys, size_t count);

			/**
			 * The name of the axis.
			 */
			std::string name;
			/**
			 * An array of all the keys that affect the axis. The items in this array come in pairs such that the first affects the axis positively and the second affects the array negatively.
			 */
			std::vector<int> keys;

			/**
			 * @param input The input manager the axis is getting the inputs from.
			 * @return The value of the axis. The value can be either -1, 0, or 1.
			 */
			int getValue(Input& input);
		};

	private:
		/**
		 * The mouse position as of last getting checked. [This variable is useless, can I do anything to remove it]
		 */
		Vector2<double> _mousePos = Vector2<double>();

		/**
		 * All of the input axes that have been created.
		 */
		std::vector<Axis> _axes = std::vector<Axis>();

		/**
		 * The parent window.
		 */
		Window& window;

	public:
		/**
		 * The constructor.
		 * @param parentWindow The window that the input manages the input of.
		 */
		Input(Window& parentWindow);

		/**
		 * @param key The key to check against.
		 * @return Whether the given key is currently down.
		 */
		bool keyDown(int key);
		/**
		 * @param key The key to check against.
		 * @return Whether the given key was just pressed.
		 */
		bool keyPressed(int key);
		/**
		 * @param button The button to check against.
		 * @return Whether the given button is currently down.
		 */
		bool buttonDown(int button);
		/**
		 * @param button The button to check against.
		 * @return Whether the given button was just pressed.
		 */
		bool buttonPressed(int button);
		/**
		 * @return The current position of the mouse.
		 */
		Vector2<double> mousePos();

		/**
		 * @param axis The name of the axis to get the value of.
		 * @return The value of the given axis.
		 */
		int getAxisValue(std::string axis);
		/**
		 * Adds an axis to the input manager.
		 * @param axis The axis to add to the list of axes.
		 */
		void addAxis(const Axis& axis);
	};
}