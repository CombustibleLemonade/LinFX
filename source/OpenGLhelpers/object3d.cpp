#define GL_GLEXT_PROTOTYPES 1 // Make sure OpenGL 3 functions are included

#include "object3d.h"
#include <iostream>

Object3D::Object3D(){
	// Create the buffer object
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
}

Object3D::Object3D(std::vector<GLfloat> vertices){
	Object3D();
	setVertices(vertices);
}

void Object3D::setVertices(std::vector<GLfloat> vertices){
	vertexBufferData = vertices;

	// Create vertex buffer data
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER,										// What buffer we use
				 sizeof(vertexBufferData[0]) * vertexBufferData.size(),	// Size of the data
				 &vertexBufferData[0],									// First element of data
				 GL_STATIC_DRAW);
}

void Object3D::setShaderProgram(const char *vertexShader, const char *fragmentShader){
	GLuint vsSource, fsSource;
	vsSource = glCreateShader(GL_VERTEX_SHADER);
	fsSource = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fsSource, 1, &fragmentShader, 0);
	glShaderSource(vsSource, 1, &vertexShader, 0);

	glCompileShader(vsSource);
	glCompileShader(fsSource);

	GLint success = 0;

	glGetShaderiv(fsSource, GL_COMPILE_STATUS, &success);
	if (!success){
		GLint maxLength = 0;
		glGetShaderiv(fsSource, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infolog(maxLength);
		glGetShaderInfoLog(fsSource, maxLength, &maxLength, &infolog[0]);
		std::cout << infolog.data() << std::endl;

		return;
	}
	glGetShaderiv(vsSource, GL_COMPILE_STATUS, &success);
	if (!success){
		GLint maxLength = 0;
		glGetShaderiv(fsSource, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infolog(maxLength);
		glGetShaderInfoLog(fsSource, maxLength, &maxLength, &infolog[0]);
		std::cout << infolog.data() << std::endl;

		return;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vsSource);
	glAttachShader(shaderProgram, fsSource);

	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (success == GL_FALSE){
		GLint maxLength = 0;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infolog(maxLength);
		glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, &infolog[0]);
		std::cout << infolog.data() << std::endl;
		return;
	}

	glDetachShader(shaderProgram, vsSource);
	glDetachShader(shaderProgram, fsSource);
}

void Object3D::draw(){
	glDisable(GL_TEXTURE_2D);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
				0,
				3,
				GL_FLOAT,
				GL_FALSE,
				0,
				(void*)0 );

	// Draw triangle
	glUseProgram(shaderProgram);
//	std::cout << glGetError() << std::endl;
	glDrawArrays(mode, 0, vertexBufferData.size()/3);
	glDisableVertexAttribArray(0);
}
