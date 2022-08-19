#include "time.h"

using namespace Charps;

double Time::deltaTime, Time::lastTime = 0;

double Time::getTime() {
	return (double) std::chrono::system_clock::duration().count();
}

void Time::update() {
	double time = getTime();
	deltaTime = time - lastTime;

	lastTime = getTime();
}