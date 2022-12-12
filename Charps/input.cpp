#include "window.h"

using namespace Charps;

Input::Axis::Axis(const char* name, std::vector<int>& keys) {
	this->keys = keys;
	this->name = name;

	this->keys.resize(this->keys.size() - this->keys.size() % 2);
}

int Input::Axis::getValue(const Input* input) const {
	bool pos = 0, neg = 0;
	for (auto key = keys.begin(); key != keys.end(); ++key) {
		if (input->keyDown(*key)) neg = true;
		key++;
		if (input->keyDown(*key)) pos = true;
	}
	return pos - neg;
}

Input::Input(Window& window) : window(window) {};

bool Input::keyDown(const int key) const {
	return glfwGetKey(window.windowGLFW, key);
}

bool Input::buttonDown(const int button) const {
	return glfwGetMouseButton(window.windowGLFW, button);
}

Vector2<double> Input::mousePos() const {
	Vector2<double> pos;
	glfwGetCursorPos(window.windowGLFW, &pos.x, &pos.y);
	return pos;
}

int Input::getAxisValue(const std::string axis) const {
	for (auto _axis = _axes.begin(); _axis != _axes.end(); ++_axis) {
		if (axis == _axis->name) {
			return _axis->getValue(this);
		}
	}
	return 0;
}

void Input::addAxis(const Axis& axis) {
	_axes.push_back(axis);
}

void Input::addAxis(const char* name, std::vector<int>& keys) {
	_axes.push_back(Axis(name, keys));
}
