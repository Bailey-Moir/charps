#include "window.h"
#include "texturemodel.h"
#include "input.h"

using namespace Charps;

Window::Window(const unsigned int width, const unsigned int height, const std::string title) : input(Input(*this)) {
	this->_size = Vector2<unsigned int>(width, height);
	this->_title = title;
	this->_pos = Vector2<unsigned int>();
}

void Window::init() {
	if (!glfwInit()) exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	windowGLFW = glfwCreateWindow(640, 480, _title.c_str(), 0, 0);
	if (windowGLFW == 0) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(windowGLFW);

	glfwSetErrorCallback([](int code, const char* description) {
		std::cout << "ERROR(" << code << "): " << description << ".";
	});

	GLint err = glewInit();
	if (err != 0) {
		printf("ERROR: %s", glewGetErrorString(err));
		throw std::exception("Unable to initialize GLEW");
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

	// insert size callback

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
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(windowGLFW);
}

void Window::renderModel(const TexturedModel& texturedModel) {
	glBindVertexArray(texturedModel.vaoID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glActiveTexture(GL_TEXTURE0); //What texture bank.
	glBindTexture(GL_TEXTURE_2D, texturedModel.textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glDrawElements(GL_TRIANGLES, texturedModel.vertexCount, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glBindVertexArray(0);
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

void Window::setTitle(const std::string v) {
	_title = v;
}
std::string Window::getTitle() {
	return _title;
}

