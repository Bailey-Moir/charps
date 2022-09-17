#include <iostream>
#include "window.h"
#include "gameobject.h"
#include "spriterenderer.h"
#include "shader.h"

using namespace Charps;

int main() {
	Window window(100, 100, "hi");
	window.init();

	GameObject thing(window);

	thing.addComponent(new SpriteRenderer(thing));

	GLfloat const Vertices[] = {
		-0.5f, 0.5f,
		0.5f, 0.5f,
		0.5f, -0.5f,
		-0.5f, -0.5f
	};

	GLuint const Elements[] = {
		0, 1, 3,
		3, 1, 2
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Elements), Elements, GL_STATIC_DRAW);

	Shader shader("mainVertex.glsl", "mainFragment.glsl");
	shader.start();

	GLint PositionAttribute = glGetAttribLocation(shader.getID(), "position");
	glEnableVertexAttribArray(PositionAttribute);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(PositionAttribute, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	while (!glfwWindowShouldClose(window.windowGLFW)) {
		window.update();

		window.render();
	}

	shader.~Shader();

	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

	glfwTerminate();
	return 0;
}