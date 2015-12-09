#include "effect.h"

#include <iostream>
#include "print.h"

GLuint Effect::defaultFramebuffer = -1;
GLuint Effect::defaultTexture;
GLuint Effect::defaultDepthRenderBuffer;

Effect::Effect(){
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

	// Framebuffer
	glGenFramebuffers(1, &defaultFramebuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, defaultFramebuffer);

	// Texture
	glGenTextures(1, &defaultTexture);
	glBindTexture(GL_TEXTURE_2D, defaultTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// Depthbuffer
	glGenRenderbuffers(1, &defaultDepthRenderBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, defaultDepthRenderBuffer);
	glFramebufferRenderbuffer(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
							  GL_TEXTURE_2D, defaultTexture);

	glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
						   GL_TEXTURE_2D, defaultTexture, 0);
	GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
	glDrawBuffers(1, drawBuffers);

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
	}

	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLubyte b[4] = {0, 255, 100, 0};
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1, 1,
				0, GL_RGB, GL_UNSIGNED_BYTE, b);

	screen.setVertices({
						 0.0f,  1.0f, 0.0f,
						-1.0f,  1.0f, 0.0f,
						-1.0f, -1.0f, 0.0f,
						 1.0f, -1.0f, 0.0f,
					});
	screen.draw();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

//	glBindFramebuffer(GL_FRAMEBUFFER, defaultFramebuffer);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


}
