#include "spriterenderer.h"
#include "GLFW.h"
#include <iostream>

using namespace Charps;

SpriteRenderer::SpriteRenderer(GameObject& gameObject) : Component(gameObject, typeid(SpriteRenderer)), shader(defaultShader) {}

void SpriteRenderer::render() {
	GLfloat const Vertices[] = {
			-0.5f, 0.5f,
			0.5f, 0.5f,
			0.5f, -0.5f,
			-0.5f, -0.5f
	};

	GLuint const Indicies[] = {
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
	
	GLint PositionAttribute = glGetAttribLocation(shader.getID(), "position");
	glVertexAttribPointer(PositionAttribute, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indicies), Indicies, GL_STATIC_DRAW);

	glBindVertexArray(0);

	glBindVertexArray(VAO);

	glEnableVertexAttribArray(PositionAttribute);	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(PositionAttribute);

	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glBindVertexArray(0);
}

void SpriteRenderer::update() {}