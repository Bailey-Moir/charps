#include "time.h"
#include "GLFW.h"

using namespace Charps;
using namespace std;

void Time::update() {
	double time = glfwGetTime();
	deltaTime = time - lastTime;
	lastTime = time;
}