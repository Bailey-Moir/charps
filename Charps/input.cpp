#include "input.h"
#include "window.h"

using namespace Charps;

Input::Axis::Axis(std::string name, int* keys, size_t count) {
	this->keys = std::vector<int>(keys, keys + count);
	this->name = name;

	this->keys.resize(count - count % 2);
}

int Input::Axis::getValue(Input& input) {
	int pos = 0, neg = 0;
	for (auto key = keys.begin(); key != keys.end(); ++key) {
		if (input.keyDown(*key) && !neg) neg = 1;
		++key;
		if (input.keyDown(*key) && !pos) pos = 1;
	}
	return pos - neg;
}

Input::Input(Window& window) : window(window) {};

bool Input::keyDown(int key) {
	int val = glfwGetKey(window.windowGLFW, key);
	return val == 1 || val == 2;
}

bool Input::keyPressed(int key) {
	return glfwGetKey(window.windowGLFW, key) == 1;
}

bool Input::buttonDown(int button) {
	int val = glfwGetMouseButton(window.windowGLFW, button);
	return val == 2 || val == 1;
}

bool Input::buttonPressed(int button) {
	return glfwGetMouseButton(window.windowGLFW, button) == 1;
}

Vector2<double> Input::mousePos() {
	glfwGetCursorPos(window.windowGLFW, &_mousePos.x, &_mousePos.y);
	return _mousePos;
}

int Input::getAxisValue(std::string axis) {
	/**
	 * How to loop through vector???
	 */
	for (auto _axis = _axes.begin(); _axis != _axes.end(); ++_axis)
	{
		if (axis == _axis->name) {
			return _axis->getValue(*this);
		}
	}
	return 0;
}

void Input::addAxis(const Axis& axis) {
	_axes.push_back(axis);
}