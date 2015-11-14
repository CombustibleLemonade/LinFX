#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "hooker.h"
#include "headerfile.h"

#include <iostream>

template<typename Return, typename... Args>
Hooker<Return, Args...>::Hooker(const char* hook){
	f = (fType)dlsym(RTLD_NEXT, hook);
}

template<typename Return, typename... Args>
Return Hooker<Return, Args...>::operator ()(Args... arguments){
	return (*f)(arguments...);
}

void testFunc() {}

void glXSwapBuffers(Display *dpy, GLXDrawable drawable){
	lglClear(GL_DEPTH_BUFFER_BIT);
	lglDisable(GL_LIGHTING);
	glColor4f(0.3f, 1.0f, 1.0f, 0.5f);
	lglBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lglBegin(GL_TRIANGLES);
	lglVertex2f(-10.0f, 0.0f);
	lglVertex2f(0.0f, -10.0f);
	lglVertex2f(10.0f, 0.0f);
	lglEnd();
	lglEnable(GL_LIGHTING);
	//lglMatrixMode(GL_MODELVIEW);
	lglXSwapBuffers(dpy, drawable);
}

GLXContext glXCreateContext(Display *dpy, XVisualInfo *vis, GLXContext shareList, int direct){

	Hooker<GLXContext, Display*, XVisualInfo*, GLXContext, int> hooker(__FUNCTION__);
	hooker(dpy, vis, shareList, direct);
}
