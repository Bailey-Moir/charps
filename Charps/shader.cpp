#include "shader.h"
#include <iostream>
#include "GLFW.h"
#include "fileutils.h"

using namespace Charps;
using namespace std;

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

inline void Shader::stop() const {
    glUseProgram(0);
}

const int Shader::getID() const {
	return id;
}

void Shader::bindAttributes() const {
    bindAttribute(0, "position");
    bindAttribute(1, "color");
}

inline void Shader::bindAttribute(int attrib, const char* name) const {
    glBindAttribLocation(id, attrib, name);
}

unsigned int Shader::loadShader(string file, unsigned int type) const {
    int shaderID = glCreateShader(type);

    string shaderStr = FileUtils::readFile(file.c_str());
    const char* shaderSrc = shaderStr.c_str();

    glShaderSource(shaderID, 1, &shaderSrc, NULL);
    glCompileShader(shaderID);
    
    GLint compileStatus;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
    if (!compileStatus) cerr << "ERROR: Could not compile shader \'" << file << "\'! " << endl;

    return shaderID;
}