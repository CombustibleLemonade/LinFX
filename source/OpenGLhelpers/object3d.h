#ifndef OGLH_DRAWABLE
#define OGLH_DRAWABLE

#include <GL/glx.h>
#include <vector>

class Object3D{
	GLuint vertexBuffer;
	std::vector<GLfloat> vertexBufferData;

	GLuint UVBuffer;
	std::vector<GLfloat> UVBufferData;

	GLuint VertexArrayID;
	GLuint shaderProgram;
	bool hasShaderProgram = false;

	GLint attributeUV = -1;
	GLint attributeTex = -1;
public:
	GLenum mode = GL_TRIANGLES;

	Object3D();
	Object3D(std::vector<GLfloat> vertices);

	void setVertices(std::vector<GLfloat> vertices);
	void setUV(std::vector<GLfloat> UV);

	void setShaderProgram(const char* vertexShader, const char* fragmentshader);
	void draw();
};

#endif
