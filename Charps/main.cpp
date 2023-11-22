#include <iostream>
#include "window.h"
#include "gameobject.h"
#include "spriterenderer.h"
#include "rigidbody.h"

using namespace Charps;
using namespace std;

int main() {
	Window window(1000, 750, "");
	
	Shader shader = Shader("mainVertex.glsl", "mainFragment.glsl");
	shader.start();

	GameObject player;
	SpriteRenderer sr(player, &shader);
	RigidBody rb(player, 1);
	rb.gravity = 0;

	GameObject obj;
	SpriteRenderer obj_sr(obj, &shader);
	RigidBody obj_rb(obj, 1);

	obj.transform.position = Vector2<double>(0, -2);
	obj_rb.gravity = 0;
	obj_sr.setColor(0.5, 0.5, 0.5);

	while (!glfwWindowShouldClose(window.windowGLFW)) {
		window.update();

		char title[50];
		sprintf_s(title, "Game: %.2f FPS", 1/window.time.deltaTime);
		window.setTitle(title);

		rb.force = Vector2<double>(window.input.getAxisValue("horizontal"), window.input.getAxisValue("vertical"));
		if (window.input.keyDown(GLFW_KEY_ESCAPE)) {
			rb.force = Vector2<double>(0);	
			rb.velocity = Vector2<double>(0);
			player.transform.position = Vector2<double>(0);
		}

		if (window.input.keyDown(GLFW_KEY_F)) rb.gravity = -9.81;
		else rb.gravity = 0;

		// RENDERING
		window.render();
	}

	glfwTerminate();
	return 0;
}