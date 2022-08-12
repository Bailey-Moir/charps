#include "window.h"

using namespace Charps;

Window::Window(int width, int height, string title) {
	this->_size = Vector2<int>(width, height);
	this->_title = title;
}

void Window::init() {
	if (!glfwInit()) throw exception("Unable to initialize GLFW");

	windowGLFW = glfwCreateWindow(640, 480, "Hello World", 0, 0);
	if (windowGLFW == 0) {
		glfwTerminate();
		throw new exception("Failed to create GLFW window");
	}

	const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	if (videoMode == 0) throw new exception("Failed to get video mode");
	_pos.x = (videoMode->width - _size.x) / 2;
	_pos.y = (videoMode->height - _size.y) / 2;
	glfwSetWindowPos(windowGLFW, _pos.x, _pos.y);
	glfwMakeContextCurrent(windowGLFW);
	
	//createCapabilities(); //Adds the ability to render to the window in
	glEnable(GL_DEPTH_TEST);

	/*sizeCallback = GLFWWindowSizeCallback() {
			public void invoke(long window, int w, int h) {
				WIDTH = w;
				HEIGHT = h;
				isResized = true;
			}
	};
	GLFW.glfwSetKeyCallback(window, input.getKeyboardCallback());
	GLFW.glfwSetCursorPosCallback(window, input.getMouseMoveCallback());
	GLFW.glfwSetMouseButtonCallback(window, input.getMouseButtonsCallback());
	GLFW.glfwSetScrollCallback(window, input.getScrollCallback());
	GLFW.glfwSetWindowSizeCallback(window, sizeCallback);*/

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

void Window::setSize(Vector2<int> v) {
	_size = v;
	glViewport(_pos.x, _pos.y, v.x, v.y);
}

Vector2<int> Window::getSize() {
	return _size;
}

void Window::setPosition(Vector2<int> v) {
	_pos = v;
	glViewport(v.x, v.y, _size.x, _size.y);
}
Vector2<int> Window::getPosition() {
	return _pos;
}

void Window::setTitle(string v) {
	_title = v;
}
string Window::getTitle() {
	return _title;
}