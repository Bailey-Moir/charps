#include "time.h"
#include "GLFW.h"

using namespace Charps;

void Time::update() {
	double time = glfwGetTime();
	deltaTime = time - lastTime;

	lastTime = glfwGetTime();
}