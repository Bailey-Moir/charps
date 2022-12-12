#include "spriterenderer.h"
#include "GLFW.h"
#include <iostream>
#include "gameobject.h"
#include "window.h"

using namespace Charps;

const int SpriteRenderer::_indicies[6] = {
	0, 1, 3,
	3, 1, 2
};

std::vector<SpriteRenderer*> SpriteRenderer::renderers = std::vector<SpriteRenderer*>();

SpriteRenderer::SpriteRenderer(GameObject& gameObject, Shader* shader) : Component(gameObject, typeid(SpriteRenderer)) {
	renderers.push_back(this);
	this->shader = shader;

	glGenVertexArrays(1, &_VAO);
	glBindVertexArray(_VAO);
	glGenBuffers(1, &_verticesVBO);
	glGenBuffers(1, &_colorVBO);
	glGenBuffers(1, &_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indicies), _indicies, GL_STATIC_DRAW);
	glBindVertexArray(0);
}

SpriteRenderer::~SpriteRenderer() {
	glBindVertexArray(_VAO);
	glDeleteBuffers(1, &_EBO);
	glDeleteBuffers(1, &_verticesVBO);
	glDeleteBuffers(1, &_colorVBO);
	glDeleteVertexArrays(1, &_VAO);
	glBindVertexArray(0);
}

void SpriteRenderer::render() {
	int physicalSize, windowWidth, windowHeight;
	glfwGetMonitorPhysicalSize(gameObject.window.monitor, &physicalSize, 0);
	glfwGetWindowSize(gameObject.window.windowGLFW, &windowWidth, &windowHeight);
	float size = (float) glfwGetVideoMode(gameObject.window.monitor)->width;

	const float Kx = size / physicalSize / windowWidth * 20,
				Ky = size / physicalSize / windowHeight * 20;

	#define POS gameObject.transform.position
	#define SIZE gameObject.transform.size

	std::array<float, 8> vertices = {
		(float)(Kx * (POS.x - SIZE.x / 2)), (float)(Ky * (POS.y + SIZE.y / 2)),
		(float)(Kx * (POS.x + SIZE.x / 2)), (float)(Ky * (POS.y + SIZE.y / 2)),
		(float)(Kx * (POS.x + SIZE.x / 2)), (float)(Ky * (POS.y - SIZE.y / 2)),
		(float)(Kx * (POS.x - SIZE.x / 2)), (float)(Ky * (POS.y - SIZE.y / 2))
	};

	GLuint verticesLocation = glGetAttribLocation(shader->getID(), "position");
	GLuint colorLocation = glGetAttribLocation(shader->getID(), "color");

	glBindVertexArray(_VAO);

	if (vertices != _lastVertices) {
		glBindBuffer(GL_ARRAY_BUFFER, _verticesVBO);
		glBufferData(GL_ARRAY_BUFFER, 8*sizeof(float), vertices.data(), GL_STATIC_DRAW);
		glVertexAttribPointer(verticesLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		_lastVertices = vertices;
	}

	if (_colorChanged) {
		float usedColor[12];
		for (int i = 0; i < 12; i++) usedColor[i] = _color[i % 3];

		glBindBuffer(GL_ARRAY_BUFFER, _colorVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(usedColor), usedColor, GL_STATIC_DRAW);
		glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		_colorChanged = false;
	}

	glEnableVertexAttribArray(colorLocation);
	glEnableVertexAttribArray(verticesLocation);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(verticesLocation);
	glDisableVertexAttribArray(colorLocation);

	glBindVertexArray(0);
}

void SpriteRenderer::update() {}

inline float SpriteRenderer::calculateColor(int n, double t) const {
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

void SpriteRenderer::getColor(float* r, float* g, float* b) const {
	*r = _color[0];
	*g = _color[1];
	*b = _color[2];
}
void SpriteRenderer::setColor(const float r, const float g, const float b) {
	_color[0] = r;
	_color[1] = g;
	_color[2] = b;
	_colorChanged = true;
}