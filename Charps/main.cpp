#include <iostream>
#include "window.h"
#include "gameobject.h"
#include "spriterenderer.h"

using namespace Charps;

int main() {
	Window window(100, 100, "hi");
	window.init();

	defaultShader.start();

	GameObject object(window);

	auto sr = SpriteRenderer(object);

	while (!glfwWindowShouldClose(window.windowGLFW)) {
		window.update();

		// RENDERING
		window.render();

		sr.render();

		glfwSwapBuffers(window.windowGLFW);
	}

	defaultShader.~Shader();

	glfwTerminate();
	return 0;
}