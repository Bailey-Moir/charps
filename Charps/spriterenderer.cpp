#include "spriterenderer.h"
#include "GLFW.h"
#include <iostream>
#include "gameobject.h"
#include "window.h"

using namespace Charps;

std::vector<SpriteRenderer*> SpriteRenderer::renderers = std::vector<SpriteRenderer*>();

SpriteRenderer::SpriteRenderer(GameObject& gameObject, Shader& shader) : Component(gameObject, typeid(SpriteRenderer)), shader(shader) {
	renderers.push_back(this);
}

void SpriteRenderer::render() {
	int physicalSize, windowWidth, windowHeight;
	glfwGetMonitorPhysicalSize(gameObject.window.monitor, &physicalSize, 0);
	glfwGetWindowSize(gameObject.window.windowGLFW, &windowWidth, &windowHeight);
	float size = (float) glfwGetVideoMode(gameObject.window.monitor)->width;

	auto xvertices = size / physicalSize / windowWidth * 10;
	auto yvertices = size / physicalSize / windowHeight * 10;

	GLfloat const Vertices[] = {
		(GLfloat) (xvertices*(-gameObject.transform.size.x + gameObject.transform.position.x)), (GLfloat) (yvertices*(gameObject.transform.size.y + gameObject.transform.position.y)),
		(GLfloat) (xvertices*(gameObject.transform.size.x + gameObject.transform.position.x)), (GLfloat) (yvertices*(gameObject.transform.size.y + gameObject.transform.position.y)),
		(GLfloat) (xvertices*(gameObject.transform.size.x + gameObject.transform.position.x)), (GLfloat) (yvertices*(-gameObject.transform.size.y + gameObject.transform.position.y)),
		(GLfloat) (xvertices*(-gameObject.transform.size.x + gameObject.transform.position.x)), (GLfloat) (yvertices*(-gameObject.transform.size.y + gameObject.transform.position.y))
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