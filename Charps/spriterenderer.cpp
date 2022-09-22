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
	float size = (float)glfwGetVideoMode(gameObject.window.monitor)->width;

	auto xvertices = size / physicalSize / windowWidth * 20;
	auto yvertices = size / physicalSize / windowHeight * 20;

	GLfloat const Vertices[] = {
		(GLfloat)(xvertices * (-gameObject.transform.size.x/2 + gameObject.transform.position.x)), (GLfloat)(yvertices * (gameObject.transform.size.y/2 + gameObject.transform.position.y)),
		(GLfloat)(xvertices * (gameObject.transform.size.x/2 + gameObject.transform.position.x)), (GLfloat)(yvertices * (gameObject.transform.size.y/2 + gameObject.transform.position.y)),
		(GLfloat)(xvertices * (gameObject.transform.size.x/2 + gameObject.transform.position.x)), (GLfloat)(yvertices * (-gameObject.transform.size.y/2 + gameObject.transform.position.y)),
		(GLfloat)(xvertices * (-gameObject.transform.size.x/2 + gameObject.transform.position.x)), (GLfloat)(yvertices * (-gameObject.transform.size.y/2 + gameObject.transform.position.y))
	};

	GLuint const Indicies[] = {
		0, 1, 3,
		3, 1, 2
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint verticesVBO;
	glGenBuffers(1, &verticesVBO);
	glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	auto verticesLocation = glGetAttribLocation(shader.getID(), "position");
	glVertexAttribPointer(verticesLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorVBO;
	glGenBuffers(1, &colorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	float usedColor[] = {
		color[0], color[1], color[2],
		color[0], color[1], color[2],
		color[0], color[1], color[2],
		color[0], color[1], color[2]
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(usedColor), usedColor, GL_STATIC_DRAW);
	auto colorLocation = glGetAttribLocation(shader.getID(), "color");
	glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indicies), Indicies, GL_STATIC_DRAW);

	glBindVertexArray(0);

	glBindVertexArray(VAO);

	glEnableVertexAttribArray(colorLocation);
	glEnableVertexAttribArray(verticesLocation);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(verticesLocation);
	glDisableVertexAttribArray(colorLocation);

	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &verticesVBO);
	glDeleteBuffers(1, &colorVBO);
	glDeleteVertexArrays(1, &VAO);
	glBindVertexArray(0);
}

void SpriteRenderer::update() {
	auto time = fmod(glfwGetTime() * 50, 150);
	color[0] = 1 - calculateColor(25, time);
	color[1] = calculateColor(0, time);
	color[2] = calculateColor(50, time);
}

inline float SpriteRenderer::calculateColor(int n, double t) {
	return (float)(t <= n ?
		0.0f :
		(t <= 25.0f + n ?
			(t - n) / 25.0f :
			(t <= 75.0f + n ?
				1.0f :
				(t <= 100.0f + n ?
					4 + (n - t)/25.0f :
					0.0f
					)
				)
			)
		);
}