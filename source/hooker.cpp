#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#define GL_GLEXT_PROTOTYPES 1

#include "OpenGLhelpers/object3d.h"

#include "hooker.h"
#include "headerfile.h"

#include <iostream>
#include <ctime>

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

}

/**
 * @brief drawQuad draws a quad that fills the screen.
 * Also applies effects to texture.
 */
void drawQuad(){
	Object3D test;
	test.setVertices({
		 1.0f,  1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
	 });
//	test.mode = GL_QUADS;
	test.draw();
}

bool is_initialized = false;
double rotation = 0.0;

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
	//	glRotated(rotation, 0.0, 0.0, 1.0);
	rotation += 0.1;

	// Draw quad with tex coords
	drawQuad();

	//	double s = 1.0;
	//	glBegin(GL_QUADS);
	//	glTexCoord2d(1.0, 1.0); glVertex2f(s, s);
	//	glTexCoord2d(0.0, 1.0);	glVertex2f(-s, s);
	//	glTexCoord2d(0.0, 0.0); glVertex2f(-s, -s);
	//	glTexCoord2d(1.0, 0.0);	glVertex2f(s, -s);
	//	glEnd();

	glGetIntegerv(GL_VIEWPORT, viewport);
	//	GLubyte pixels[viewport[2]][viewport[3]];
	//	glReadPixels(0, 0, viewport[2], viewport[3], GL_RGB, GL_UNSIGNED_BYTE, pixels);
	//	std::cout << sizeof(pixels) << std::endl;

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

GLXContext glXCreateContext(Display *dpy, XVisualInfo *vis, GLXContext shareList, int direct){
	Hooker<GLXContext, Display*, XVisualInfo*, GLXContext, int> hooker(__FUNCTION__);
	GLXContext return_value = hooker(dpy, vis, shareList, direct);

	return return_value;
}

