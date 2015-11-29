#define GL_GLEXT_PROTOTYPES 1 // Make sure OpenGL 3 functions are included

#include "object3d.h"
#include <iostream>

Object3D::Object3D(){
	// Create the buffer object
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	mode = GL_TRIANGLES;
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
	glDrawArrays(mode, 0, vertexBufferData.size()/3);
	glDisableVertexAttribArray(0);
}
