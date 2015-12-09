#define GL_GLEXT_PROTOTYPES 1 // Make sure OpenGL 3 functions are included

#include "object3d.h"
#include <iostream>

Object3D::Object3D(){}

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

void Object3D::setUV(std::vector<GLfloat> UV){
	UVBufferData = UV;

	// Create UV buffer data
	glGenBuffers(1, &UVBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, UVBuffer);
	glBufferData(GL_ARRAY_BUFFER,								// What buffer we use
				 sizeof(UVBufferData[0]) * UVBufferData.size(),	// Size of the data
			&UVBufferData[0],								// First element of data
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

	success = 0;
	glGetShaderiv(vsSource, GL_COMPILE_STATUS, &success);
	if (!success){
		GLint maxLength = 0;
		glGetShaderiv(vsSource, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<GLchar> infolog(maxLength);
		glGetShaderInfoLog(vsSource, maxLength, &maxLength, &infolog[0]);
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


	attributeUV = glGetAttribLocation(shaderProgram, "vertexUV");
	attributeTex = glGetUniformLocation(shaderProgram, "textureSampler");

	hasShaderProgram = true;
	if (attributeUV == -1){
		std::cout << "UV not bound. " << std::endl;
		hasShaderProgram = false;
	}
	if (attributeTex == -1){
		std::cout << "Texture not bound. " << std::endl;
		hasShaderProgram = false;
	}
}

void Object3D::draw(){

	glEnable(GL_TEXTURE_2D);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(attributeUV);
//	glUseProgram(shaderProgram);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
				0,
				3,
				GL_FLOAT,
				GL_FALSE,
				0,
				(void*)0 );

	glBindBuffer(GL_ARRAY_BUFFER, UVBuffer);
	glVertexAttribPointer(
				attributeUV,		// attribute
				2,                  // number of elements per vertex, here (x,y)
				GL_FLOAT,           // the type of each element
				GL_FALSE,           // take our values as-is
				0,                  // no extra data between each position
				(void*)0			// offset of first element
				);

	glActiveTexture(GL_TEXTURE0);
	glUniform1i(attributeTex, 0);

//	glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
//	glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
//	glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
//	glVertex3f( 1.0f,-1.0f, 0.0f);            // Bottom Right
//	glEnd();                            // Finished Drawing The Triangle

	glDrawArrays(mode, 0, vertexBufferData.size()/3);

	glDisableVertexAttribArray(0);
	glEnableVertexAttribArray(attributeUV);

//	glUseProgram(0);
}
