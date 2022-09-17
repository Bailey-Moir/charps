#pragma once
#include <chrono>
#include <ctime>

namespace Charps {
	/**
	 * Manages time in the game.
	 */
	class Time {
	private:
		/**
		 * The last time the update function was called.
		 */
		static double lastTime;
	public:
		/**
		 * The time in seconds since the last frame.
		 */
		static double deltaTime;

		/**
		 * Updates the delta time variable. To be run every frame.
		 */
		static void update();
	};
}