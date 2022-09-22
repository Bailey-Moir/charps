#include <iostream>
#include "window.h"
#include "gameobject.h"
#include "spriterenderer.h"
#include "rigidbody.h"

using namespace Charps;

int main() {
	Window window(1000, 750, "hi");
	
	Shader shader = Shader("mainVertex.glsl", "mainFragment.glsl");
	shader.start();

	GameObject object(window);
	SpriteRenderer sr(object, shader);
	RigidBody rb(object, 1);

	while (!glfwWindowShouldClose(window.windowGLFW)) {
		window.update();

		object.transform.translate(Vector2<double>(window.input.getAxisValue("horizontal"), window.input.getAxisValue("vertical")) * 20);
		if (window.input.keyDown(GLFW_KEY_ESCAPE)) {
			rb.editingForce.y = 0;
			rb.velocity.y = 0;
			object.transform.position = Vector2<double>(0);
		}

		// RENDERING
		window.render();
	}

	shader.~Shader();

	glfwTerminate();
	return 0;
}