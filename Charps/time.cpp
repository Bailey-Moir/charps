#include "time.h"
#include "GLFW.h"

using namespace Charps;

double Time::deltaTime, Time::lastTime = 0;

void Time::update() {
	double time = glfwGetTime();
	deltaTime = time - lastTime;

	lastTime = glfwGetTime();
}