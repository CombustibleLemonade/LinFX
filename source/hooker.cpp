#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#define GL_GLEXT_PROTOTYPES 1

#include "hooker.h"
#include "headerfile.h"

#include "OpenGLhelpers/object3d.h"
#include "OpenGLhelpers/effect.h"
#include "OpenGLhelpers/print.h"

#include <iostream>
#include <ctime>

Effect passthrough;
Effect test;

template<typename Return, typename... Args>
Hooker<Return, Args...>::Hooker(const char* hook){
	f = (fType)dlsym(RTLD_NEXT, hook);
}

template<typename Return, typename... Args>
Return Hooker<Return, Args...>::operator ()(Args... arguments){
	return (*f)(arguments...);
}

void init(){
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
	fragmentShader += "return sin(-x * 1.570796327) * 1.2 + 1.0*x; \n";
	fragmentShader += "} \n";
	fragmentShader += "";

	fragmentShader += "void main(void){ \n";
	fragmentShader += "gl_FragColor = vec4(texture(textureSampler, UV).rgb, 1.0); \n";
	fragmentShader += "} \n";

	std::string fragmentShaderTest;
	fragmentShaderTest += "#version 330 core \n";
	fragmentShaderTest += "uniform sampler2D textureSampler; \n";
	fragmentShaderTest += "in vec2 UV; \n";

	fragmentShaderTest += "float bulge(float x){ \n";
	fragmentShaderTest += "return sin(-x * 1.570796327) * 1.2 + 1.0*x; \n";
	fragmentShaderTest += "} \n";
	fragmentShaderTest += "";

	fragmentShaderTest += "void main(void){ \n";
	fragmentShaderTest += "gl_FragColor = vec4(texture(textureSampler, UV).rgb * 10, 1.0); \n";
	fragmentShaderTest += "} \n";


	passthrough.setShaderProgram(vertexShader, fragmentShader);
	test.setShaderProgram(vertexShader, fragmentShaderTest);
}

bool is_initialized = false;

void glXSwapBuffers(Display *dpy, GLXDrawable drawable){
	if (!is_initialized){
		is_initialized = true;
		init();
	}

	passthrough.draw();
	Effect::bindSystemFramebuffer();
	passthrough.draw();

	// Swap buffers
	lglXSwapBuffers(dpy, drawable);
	Effect::bindEffectFramebuffer();
}

GLXContext glXCreateContext(Display *dpy, XVisualInfo *vis, GLXContext shareList, int direct){
	Hooker<GLXContext, Display*, XVisualInfo*, GLXContext, int> hooker(__FUNCTION__);
	GLXContext return_value = hooker(dpy, vis, shareList, direct);

	return return_value;
}
