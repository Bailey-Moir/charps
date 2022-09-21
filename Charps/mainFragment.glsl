#version 330
out vec4 outColor;
in vec4 passColor; // the input variable from the vertex shader (same name and same type)  

void main()
{
	outColor = passColor;
}