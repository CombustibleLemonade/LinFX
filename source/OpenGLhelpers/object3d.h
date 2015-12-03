#ifndef OGLH_DRAWABLE
#define OGLH_DRAWABLE

#include <GL/glx.h>
#include <vector>

class Object3D{
	GLuint vertexBuffer;
	std::vector<GLfloat> vertexBufferData;
	GLuint VertexArrayID;
	GLuint shaderProgram;
public:
	GLenum mode = GL_TRIANGLES;

	Object3D();
	Object3D(std::vector<GLfloat> vertices);

	void setVertices(std::vector<GLfloat> vertices);
	void setShaderProgram(const char* vertexShader, const char* fragmentshader);
	void draw();
};

#endif
