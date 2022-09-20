#include "shader.h"
#include <iostream>
#include "GLFW.h"
#include "fileutils.h"

using namespace Charps;

Shader::Shader(const char* vertexFile, const char* fragmentFile) : vertexID(loadShader(vertexFile, GL_VERTEX_SHADER)), fragmentID(loadShader(fragmentFile, GL_FRAGMENT_SHADER)), id(glCreateProgram()) {
	glAttachShader(id, vertexID);
	glAttachShader(id, fragmentID);
	glBindFragDataLocation(id, 0, "outColor");
	glLinkProgram(id);
	glValidateProgram(id);
}

Shader::~Shader() {
    stop();
    glDetachShader(id, vertexID);
    glDetachShader(id, fragmentID);
    glDeleteShader(vertexID);
    glDeleteShader(fragmentID);
    glDeleteProgram(id);
}

void Shader::start() const {
    glUseProgram(id);
}

void Shader::stop() const {
    glUseProgram(0);
}

const int Shader::getID() const {
	return id;
}

void Shader::bindAttributes() const {
    bindAttribute(0, "position");
}

void Shader::bindAttribute(int attrib, const char* name) const {
    glBindAttribLocation(id, attrib, name);
}

unsigned int Shader::loadShader(std::string file, unsigned int type) const {
    int shaderID = glCreateShader(type);

    std::string shaderStr = FileUtils::readFile(file.c_str());
    const char* shaderSrc = shaderStr.c_str();

    int result = 0;

    glShaderSource(shaderID, 1, &shaderSrc, NULL);
    glCompileShader(shaderID);
    
    GLint compileStatus;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
    if (!compileStatus) std::cerr << "ERROR: Could not compile shader \'" << file << "\'! " << std::endl;

    return shaderID;
}