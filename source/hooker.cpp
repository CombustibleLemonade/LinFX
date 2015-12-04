#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#define GL_GLEXT_PROTOTYPES 1

#include "hooker.h"
#include "headerfile.h"

#include "OpenGLhelpers/object3d.h"

#include <iostream>
#include <ctime>


Object3D test;

template<typename Return, typename... Args>
Hooker<Return, Args...>::Hooker(const char* hook){
	f = (fType)dlsym(RTLD_NEXT, hook);
}

template<typename Return, typename... Args>
Return Hooker<Return, Args...>::operator ()(Args... arguments){
	return (*f)(arguments...);
}

GLuint framebufferName = 0;
GLuint renderedTexture;
GLuint depthRenderbuffer;

void init(){
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	glClear(GL_COLOR_BUFFER_BIT);
	// Framebuffer
	glGenFramebuffers(1, &framebufferName);
	glBindFramebuffer(GL_FRAMEBUFFER, framebufferName);

	glGenTextures(1, &renderedTexture);
	glBindTexture(GL_TEXTURE_2D, renderedTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, viewport[2], viewport[3], 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Depthbuffer
	glGenRenderbuffers(1, &depthRenderbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, viewport[2], viewport[3]);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer);

	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, renderedTexture, 0);

	GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
	glDrawBuffers(1, drawBuffers);

	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
		std::cout << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
		std::cout << glGetError() << std::endl;
	}

//	glPushMatrix();
//	glTranslated(0.0, 0.0, 20.0);
//	GLfloat modelVmatrix[16];
//	glGetFloatv(GL_MODELVIEW_MATRIX, modelVmatrix);

//	std::cout << modelVmatrix << std::endl;
//	for (int i = 0; i < 4; i++){
//		for (int j = 0; j < 4; j++){
//			std::cout << modelVmatrix[i*4+j] << "\t";
//		}
//		std::cout << std::endl;
//	}
//	glPopMatrix();

	test.setVertices({
					 1.0f,  1.0f, 0.0f,
					-1.0f,  1.0f, 0.0f,
					-1.0f, -1.0f, 0.0f,
					 1.0f, -1.0f, 0.0f,
				});

	test.setUV({
					 1.0f, 1.0f,
					 0.0f, 1.0f,
					 0.0f, 0.0f,
					 1.0f, 0.0f
				});

	std::string vertexShader;
	vertexShader += "#version 330 core \n";
	vertexShader += "layout(location = 0) in vec3 vertexPosition_modelspace;";
	vertexShader += "layout(location = 1) in vec2 vertexUV;";
	vertexShader += "out vec2 UV;";
	vertexShader += "void main(){";
	vertexShader += "gl_Position = vec4(vertexPosition_modelspace, 1);";
	vertexShader += "UV = vertexUV;";
	vertexShader += "}";


	std::string fragmentShader;
	fragmentShader += "#version 330 core \n";
	fragmentShader += "uniform sampler2D textureSampler; \n";
	fragmentShader += "in vec2 UV; \n";

	fragmentShader += "float bulge(float x){ \n";
	fragmentShader += "return sin(-x * 1.570796327) * 1.2 + 1.0*x;";
	fragmentShader += "}";
	fragmentShader += "";

	fragmentShader += "void main(void){ \n";
	fragmentShader += "vec2 UVedit = UV; \n";
	fragmentShader += "UVedit = vec2(UVedit.x, UVedit.y);";
	fragmentShader += "gl_FragColor = vec4(texture(textureSampler, UVedit).rgb * 0.2, 1.0); \n";
	fragmentShader += "} \n";

	test.setShaderProgram(vertexShader.c_str(), fragmentShader.c_str());
}

/**
 * @brief drawQuad draws a quad that fills the screen.
 * Also applies effects to texture.
 */
void drawQuad(){
	test.mode = GL_QUADS;
	test.draw();
}

bool is_initialized = false;
double rotation = 0.0;

int i = 0;

void glXSwapBuffers(Display *dpy, GLXDrawable drawable){
	if (!is_initialized){
		is_initialized = true;
		init();
	}

	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);

	/* --- Draw rendered texture to screen --- */
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, renderedTexture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Push matrices
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	// Draw quad with tex coords
	drawQuad();

	glUseProgram(0);


	// Pop matrices
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);

	// Swap buffers
	lglXSwapBuffers(dpy, drawable);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	// Do framebuffer magic
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, framebufferName);
	glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, renderedTexture, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, viewport[2], viewport[3], 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, viewport[2], viewport[3]);
}


//void glBindFramebuffer(GLenum target, GLuint framebuffer){
//	lglBindFramebuffer(target, framebuffer);
//}


GLXContext glXCreateContext(Display *dpy, XVisualInfo *vis, GLXContext shareList, int direct){
	Hooker<GLXContext, Display*, XVisualInfo*, GLXContext, int> hooker(__FUNCTION__);
	GLXContext return_value = hooker(dpy, vis, shareList, direct);

	return return_value;
}


