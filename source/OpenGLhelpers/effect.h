#ifndef EFFECT_LINFX
#define EFFECT_LINFX

#define GL_GLEXT_PROTOTYPES 1

#include <cstdarg>

#include <dlfcn.h>
#include <execinfo.h>

#include <GL/glx.h>
#include <GL/glext.h>
#include <GL/glu.h>

#include <iostream>
#include <typeinfo>

#include "object3d.h"

class Effect{
	static GLuint defaultTexture;
	static GLuint defaultFramebuffer;
	static GLuint defaultDepthRenderBuffer;

	bool hasInitialized;
	Object3D screen;
public:
	enum Preset{
		NONE = -1,
		BRIGHTNESS,
		BLUR,
		BLOOM,
		DIRT_LENSE};

private:
	Preset preset = NONE;
	void setPreset(Preset p);

	void setViewport(GLint v[]);
public:
	static void staticInit();
	Effect();
	Effect(Preset p);
	Effect(std::string vs, std::string fs);

	void setShaderProgram(std::string vs, std::string fs);

	void draw();
};

#endif
