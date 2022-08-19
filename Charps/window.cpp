#include "window.h"

using namespace Charps;

/*
TODO: don't do using namespace
*/

Window::Window(unsigned int width, unsigned int height, std::string title) : input(Input(*this)) {
	this->_size = Vector2<unsigned int>(width, height);
	this->_title = title;
	this->_pos = Vector2<unsigned int>();
}

void Window::init() {
	if (!glfwInit()) throw std::exception("Unable to initialize GLFW");

	windowGLFW = glfwCreateWindow(640, 480, "Hello World", 0, 0);
	if (windowGLFW == 0) {
		glfwTerminate();
		throw new std::exception("Failed to create GLFW window");
	}

	glfwSetWindowUserPointer(windowGLFW, (Window*) this);

	const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	if (videoMode == 0) throw new std::exception("Failed to get video mode");
	_pos.x = (videoMode->width - _size.x) / 2;
	_pos.y = (videoMode->height - _size.y) / 2;
	glfwSetWindowPos(windowGLFW, _pos.x, _pos.y);
	glfwMakeContextCurrent(windowGLFW);
	
	//createCapabilities(); //Adds the ability to render to the window
	glEnable(GL_DEPTH_TEST);

	int hKeys[] = {
		GLFW_KEY_A, GLFW_KEY_D,
		GLFW_KEY_LEFT, GLFW_KEY_RIGHT
	};
	input.addAxis(Input::Axis("horizontal", hKeys, sizeof(hKeys)));

	int vKeys[] = {
		GLFW_KEY_S, GLFW_KEY_W,
		GLFW_KEY_DOWN, GLFW_KEY_UP
	};
	input.addAxis(Input::Axis("vertical", vKeys, sizeof(vKeys)));

	/*sizeCallback = GLFWWindowSizeCallback() {
			public void invoke(long window, int w, int h) {
				WIDTH = w;
				HEIGHT = h;
				isResized = true;
			}
	};*/

	glfwShowWindow(windowGLFW);
	glfwSwapInterval(1);
}

void Window::update() {
	glfwPollEvents(); //Gets all the callbacks connected to the window.
}

void Window::render() {
	//Clears the screen and sets the background color
	glClearColor(color[0], color[1], color[2], 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Or bit
	glfwSwapBuffers(windowGLFW);
}

void Window::setSize(const Vector2<unsigned int>& v) {
	_size = v;
	glViewport(_pos.x, _pos.y, v.x, v.y);
}

Vector2<unsigned int> Window::getSize() {
	return _size;
}

void Window::setPosition(const Vector2<unsigned int>& v) {
	_pos = v;
	glViewport(v.x, v.y, _size.x, _size.y);
}
Vector2<unsigned int> Window::getPosition() {
	return _pos;
}

void Window::setTitle(std::string v) {
	_title = v;
}
std::string Window::getTitle() {
	return _title;
}

