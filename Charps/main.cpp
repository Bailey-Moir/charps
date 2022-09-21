#include <iostream>
#include "window.h"
#include "gameobject.h"
#include "spriterenderer.h"

using namespace Charps;

int main() {
	Window window(100, 100, "hi");
	
	Shader shader = Shader("mainVertex.glsl", "mainFragment.glsl");
	shader.start();

	GameObject object(window);
	SpriteRenderer sr(object, shader);

	while (!glfwWindowShouldClose(window.windowGLFW)) {
		window.update();

		object.transform.position += Vector2<double>(window.input.getAxisValue("horizontal"), window.input.getAxisValue("vertical"));

		// RENDERING
		window.render();
	}

	shader.~Shader();

	glfwTerminate();
	return 0;
}