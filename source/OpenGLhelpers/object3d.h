#ifndef OGLH_DRAWABLE
#define OGLH_DRAWABLE

#include <GL/glx.h>
#include <vector>

class Object3D{
	GLuint vertexBuffer;
	std::vector<GLfloat> vertexBufferData;
	GLuint VertexArrayID;
public:
	GLenum mode;

	Object3D();

	void setVertices(std::vector<GLfloat> vertices);
	void draw();
};

#endif
