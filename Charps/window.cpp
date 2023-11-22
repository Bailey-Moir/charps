#include "window.h"
#include "spriterenderer.h"

using namespace Charps;
using namespace std;

Window* Window::context = NULL;

Window::Window(const unsigned int width, const unsigned int height, const string title) : input(Input(*this)), time(Time()) {
	this->_title = title;

	glfwSetErrorCallback([](int code, const char* desc) { printf("ERROR(%d): %s\n", code, desc); });
	if (!glfwInit()) exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	windowGLFW = glfwCreateWindow(width, height, _title.c_str(), 0, 0);
	if (!windowGLFW) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(windowGLFW);
	monitor = glfwGetPrimaryMonitor();

	GLint err = glewInit();
	if (err) {
		printf("ERROR(%d): %s\n", err, glewGetErrorString(err));
		throw exception("Unable to initialize GLEW");
	}

	const GLFWvidmode* videoMode = glfwGetVideoMode(monitor);
	if (videoMode == 0) throw new exception("Failed to get video mode");
	glfwSetWindowPos(windowGLFW, (videoMode->width - width) / 2, (videoMode->height - height) / 2);

	//createCapabilities(); //Adds the ability to render to the window
	glEnable(GL_DEPTH_TEST);

	//glfwSetWindowUserPointer(windowGLFW, this);

	glfwSetWindowSizeCallback(windowGLFW, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });

	// default axis
	vector<int> hKeys = {
		GLFW_KEY_A, GLFW_KEY_D,
		GLFW_KEY_LEFT, GLFW_KEY_RIGHT
	};
	input.addAxis("horizontal", hKeys);

	vector<int> vKeys = {
		GLFW_KEY_S, GLFW_KEY_W,
		GLFW_KEY_DOWN, GLFW_KEY_UP
	};
	input.addAxis("vertical", vKeys);

	glfwShowWindow(windowGLFW);
	glfwSwapInterval(1);
	//glfwSwapInterval(1);

	context = this;
}

void Window::update() {
	time.update();
	glfwPollEvents(); //Gets all the callbacks connected to the window.
	for (auto component = Component::allComponents.begin(); component != Component::allComponents.end(); ++component) {
		if (*component == nullptr) Component::allComponents.erase(component);
		else (*component)->update();
	}
}

void Window::render() {
	glClearColor(color[0], color[1], color[2], 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Or bit

	for (auto sr : SpriteRenderer::renderers) sr->render();

	glfwSwapBuffers(windowGLFW);
}

void Window::setTitle(const char* v) {
	_title = v;
	glfwSetWindowTitle(windowGLFW, v);
}

string Window::getTitle() const {
	return _title;
}