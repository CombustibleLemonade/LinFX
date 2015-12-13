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

void printTextureInfo(GLuint texID){
	bool isTexture = glIsTexture(texID);
	if (isTexture){
		// Cache old texture
		GLint texturecache;
		glGetIntegerv(GL_ACTIVE_TEXTURE, &texturecache);

		// Bind texture to print info about
		glBindTexture(GL_TEXTURE_2D, texID);

		std::cout << texID << " is a texture!" << std::endl;

		GLfloat w, h;
		glGetTexLevelParameterfv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
		glGetTexLevelParameterfv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);

		std::cout << "dimensions: " << w << "x" << h << std::endl;

		// Rebind old texture
		glBindTexture(GL_TEXTURE_2D, texturecache);
	} else {
		std::cout << texID << " is not a texture!" << std::endl;
	}
}
