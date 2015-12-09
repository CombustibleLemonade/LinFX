#define GL_GLEXT_PROTOTYPES 1

#include <GL/gl.h>
#include <iostream>

#include <GL/glx.h>
#include <GL/glext.h>
#include <GL/glu.h>

void printModelviewMatrix(){
	GLfloat modelVmatrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, modelVmatrix);

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			std::cout << modelVmatrix[i*4+j] << "\t";
		}
		std::cout << std::endl;
	}
}
