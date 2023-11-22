#pragma once
#include <chrono>
#include <ctime>

using namespace std;

namespace Charps {
	/**
	 * Manages time in the game.
	 */
	class Time {
	private:
		/**
		 * The last time the update function was called.
		 */
		double lastTime = 0;
	public:
		/**
		 * The time in seconds since the last frame.
		 */
		double deltaTime = 0;

		/**
		 * Updates the delta time variable. To be run every frame.
		 */
		void update();
	};
}