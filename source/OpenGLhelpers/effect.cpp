#include "effect.h"

#include <iostream>
#include "print.h"

GLuint Effect::defaultFramebuffer = -1;
GLuint Effect::defaultTexture;
GLuint Effect::defaultDepthRenderBuffer;

Effect::Effect(){
	screen.mode = GL_QUADS;
}

Effect::Effect(Preset p){
	Effect();
	setPreset(p);
}

Effect::Effect(std::string vs, std::string fs){
	Effect();
	setShaderProgram(vs, fs);
}

void Effect::setShaderProgram(std::string vs, std::string fs){
	screen.setShaderProgram(vs.c_str(), fs.c_str());
}

// TODO
void Effect::staticInit(){
	glClear(GL_COLOR_BUFFER_BIT);
	defaultFramebuffer = 0;

	// Get screen size
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	// Framebuffer
	glGenFramebuffers(1, &defaultFramebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, defaultFramebuffer);

	// Texture
	glGenTextures(1, &defaultTexture);
	glBindTexture(GL_TEXTURE_2D, defaultTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, viewport[2], viewport[3],
				 0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Depthbuffer
	glGenRenderbuffers(1, &defaultDepthRenderBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, defaultDepthRenderBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, viewport[2], viewport[3]);

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
							  GL_RENDERBUFFER, defaultDepthRenderBuffer);

	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
						   GL_TEXTURE_2D, defaultTexture, 0);

	GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
	glDrawBuffers(1, drawBuffers);

	if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
		std::cout << "framebuffer failed: " << std::endl;
		std::cout << glCheckFramebufferStatus(GL_FRAMEBUFFER) << std::endl;
		std::cout << glGetError() << std::endl;
	}
}

void Effect::init(){
	screen.setVertices({
					 1.0f,  1.0f, 0.0f,
					-1.0f,  1.0f, 0.0f,
					-1.0f, -1.0f, 0.0f,
					 1.0f, -1.0f, 0.0f,
				});

	screen.setUV({
					 1.0f, 1.0f,
					 0.0f, 1.0f,
					 0.0f, 0.0f,
					 1.0f, 0.0f
				});
}

// TODO
void Effect::setPreset(Preset p){
	preset = p;
}

void Effect::setViewport(GLint v[]){

}

// TODO
void Effect::draw(){
	if (defaultFramebuffer == -1){
		staticInit();
		init();
	}

	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	screen.draw();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Effect::bindEffectFramebuffer(){

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	// Do framebuffer magic
	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, defaultFramebuffer);
	glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, viewport[2], viewport[3], 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

	// Resize depth buffer
	glBindRenderbuffer(GL_RENDERBUFFER, defaultDepthRenderBuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, viewport[2], viewport[3]);
}

void Effect::bindSystemFramebuffer(){
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
