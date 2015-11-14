#include "/usr/include/GL/glx.h"
Hooker<int> lXSupportsLocale("XSupportsLocale");
Hooker<char*> lXDefaultString("XDefaultString");
Hooker<void, GLfloat> lglClearIndex("glClearIndex");
Hooker<void, GLclampf, GLclampf, GLclampf, GLclampf> lglClearColor("glClearColor");
Hooker<void, GLbitfield> lglClear("glClear");
Hooker<void, GLuint> lglIndexMask("glIndexMask");
Hooker<void, GLboolean, GLboolean, GLboolean, GLboolean> lglColorMask("glColorMask");
Hooker<void, GLenum, GLclampf> lglAlphaFunc("glAlphaFunc");
Hooker<void, GLenum, GLenum> lglBlendFunc("glBlendFunc");
Hooker<void, GLenum> lglLogicOp("glLogicOp");
Hooker<void, GLenum> lglCullFace("glCullFace");
Hooker<void, GLenum> lglFrontFace("glFrontFace");
Hooker<void, GLfloat> lglPointSize("glPointSize");
Hooker<void, GLfloat> lglLineWidth("glLineWidth");
Hooker<void, GLint, GLushort> lglLineStipple("glLineStipple");
Hooker<void, GLenum, GLenum> lglPolygonMode("glPolygonMode");
Hooker<void, GLfloat, GLfloat> lglPolygonOffset("glPolygonOffset");
Hooker<void, GLubyte *> lglPolygonStipple("glPolygonStipple");
Hooker<void, GLubyte *> lglGetPolygonStipple("glGetPolygonStipple");
Hooker<void, GLboolean> lglEdgeFlag("glEdgeFlag");
Hooker<void, GLboolean *> lglEdgeFlagv("glEdgeFlagv");
Hooker<void, GLint, GLint, GLsizei, GLsizei> lglScissor("glScissor");
Hooker<void, GLenum, GLdouble *> lglClipPlane("glClipPlane");
Hooker<void, GLenum, GLdouble *> lglGetClipPlane("glGetClipPlane");
Hooker<void, GLenum> lglDrawBuffer("glDrawBuffer");
Hooker<void, GLenum> lglReadBuffer("glReadBuffer");
Hooker<void, GLenum> lglEnable("glEnable");
Hooker<void, GLenum> lglDisable("glDisable");
Hooker<GLboolean, GLenum> lglIsEnabled("glIsEnabled");
Hooker<void, GLenum> lglEnableClientState("glEnableClientState");
Hooker<void, GLenum> lglDisableClientState("glDisableClientState");
Hooker<void, GLenum, GLboolean *> lglGetBooleanv("glGetBooleanv");
Hooker<void, GLenum, GLdouble *> lglGetDoublev("glGetDoublev");
Hooker<void, GLenum, GLfloat *> lglGetFloatv("glGetFloatv");
Hooker<void, GLenum, GLint *> lglGetIntegerv("glGetIntegerv");
Hooker<void, GLbitfield> lglPushAttrib("glPushAttrib");
Hooker<void> lglPopAttrib("glPopAttrib");
Hooker<void, GLbitfield> lglPushClientAttrib("glPushClientAttrib");
Hooker<void> lglPopClientAttrib("glPopClientAttrib");
Hooker<GLint, GLenum> lglRenderMode("glRenderMode");
Hooker<GLenum> lglGetError("glGetError");
Hooker<GLubyte, GLenum> lglGetString("glGetString");
Hooker<void> lglFinish("glFinish");
Hooker<void> lglFlush("glFlush");
Hooker<void, GLenum, GLenum> lglHint("glHint");
Hooker<void, GLclampd> lglClearDepth("glClearDepth");
Hooker<void, GLenum> lglDepthFunc("glDepthFunc");
Hooker<void, GLboolean> lglDepthMask("glDepthMask");
Hooker<void, GLclampd, GLclampd> lglDepthRange("glDepthRange");
Hooker<void, GLfloat, GLfloat, GLfloat, GLfloat> lglClearAccum("glClearAccum");
Hooker<void, GLenum, GLfloat> lglAccum("glAccum");
Hooker<void, GLenum> lglMatrixMode("glMatrixMode");
Hooker<void> lglPushMatrix("glPushMatrix");
Hooker<void> lglPopMatrix("glPopMatrix");
Hooker<void> lglLoadIdentity("glLoadIdentity");
Hooker<void, GLdouble *> lglLoadMatrixd("glLoadMatrixd");
Hooker<void, GLfloat *> lglLoadMatrixf("glLoadMatrixf");
Hooker<void, GLdouble *> lglMultMatrixd("glMultMatrixd");
Hooker<void, GLfloat *> lglMultMatrixf("glMultMatrixf");
Hooker<void, GLdouble, GLdouble, GLdouble> lglScaled("glScaled");
Hooker<void, GLfloat, GLfloat, GLfloat> lglScalef("glScalef");
Hooker<void, GLdouble, GLdouble, GLdouble> lglTranslated("glTranslated");
Hooker<void, GLfloat, GLfloat, GLfloat> lglTranslatef("glTranslatef");
Hooker<GLboolean, GLuint> lglIsList("glIsList");
Hooker<void, GLuint, GLsizei> lglDeleteLists("glDeleteLists");
Hooker<GLuint, GLsizei> lglGenLists("glGenLists");
Hooker<void, GLuint, GLenum> lglNewList("glNewList");
Hooker<void> lglEndList("glEndList");
Hooker<void, GLuint> lglCallList("glCallList");
Hooker<void, GLuint> lglListBase("glListBase");
Hooker<void, GLenum> lglBegin("glBegin");
Hooker<void> lglEnd("glEnd");
Hooker<void, GLdouble, GLdouble> lglVertex2d("glVertex2d");
Hooker<void, GLfloat, GLfloat> lglVertex2f("glVertex2f");
Hooker<void, GLint, GLint> lglVertex2i("glVertex2i");
Hooker<void, GLshort, GLshort> lglVertex2s("glVertex2s");
Hooker<void, GLdouble, GLdouble, GLdouble> lglVertex3d("glVertex3d");
Hooker<void, GLfloat, GLfloat, GLfloat> lglVertex3f("glVertex3f");
Hooker<void, GLint, GLint, GLint> lglVertex3i("glVertex3i");
Hooker<void, GLshort, GLshort, GLshort> lglVertex3s("glVertex3s");
Hooker<void, GLdouble, GLdouble, GLdouble, GLdouble> lglVertex4d("glVertex4d");
Hooker<void, GLfloat, GLfloat, GLfloat, GLfloat> lglVertex4f("glVertex4f");
Hooker<void, GLint, GLint, GLint, GLint> lglVertex4i("glVertex4i");
Hooker<void, GLshort, GLshort, GLshort, GLshort> lglVertex4s("glVertex4s");
Hooker<void, GLdouble *> lglVertex2dv("glVertex2dv");
Hooker<void, GLfloat *> lglVertex2fv("glVertex2fv");
Hooker<void, GLint *> lglVertex2iv("glVertex2iv");
Hooker<void, GLshort *> lglVertex2sv("glVertex2sv");
Hooker<void, GLdouble *> lglVertex3dv("glVertex3dv");
Hooker<void, GLfloat *> lglVertex3fv("glVertex3fv");
Hooker<void, GLint *> lglVertex3iv("glVertex3iv");
Hooker<void, GLshort *> lglVertex3sv("glVertex3sv");
Hooker<void, GLdouble *> lglVertex4dv("glVertex4dv");
Hooker<void, GLfloat *> lglVertex4fv("glVertex4fv");
Hooker<void, GLint *> lglVertex4iv("glVertex4iv");
Hooker<void, GLshort *> lglVertex4sv("glVertex4sv");
Hooker<void, GLbyte, GLbyte, GLbyte> lglNormal3b("glNormal3b");
Hooker<void, GLdouble, GLdouble, GLdouble> lglNormal3d("glNormal3d");
Hooker<void, GLfloat, GLfloat, GLfloat> lglNormal3f("glNormal3f");
Hooker<void, GLint, GLint, GLint> lglNormal3i("glNormal3i");
Hooker<void, GLshort, GLshort, GLshort> lglNormal3s("glNormal3s");
Hooker<void, GLbyte *> lglNormal3bv("glNormal3bv");
Hooker<void, GLdouble *> lglNormal3dv("glNormal3dv");
Hooker<void, GLfloat *> lglNormal3fv("glNormal3fv");
Hooker<void, GLint *> lglNormal3iv("glNormal3iv");
Hooker<void, GLshort *> lglNormal3sv("glNormal3sv");
Hooker<void, GLdouble> lglIndexd("glIndexd");
Hooker<void, GLfloat> lglIndexf("glIndexf");
Hooker<void, GLint> lglIndexi("glIndexi");
Hooker<void, GLshort> lglIndexs("glIndexs");
Hooker<void, GLubyte> lglIndexub("glIndexub");
Hooker<void, GLdouble *> lglIndexdv("glIndexdv");
Hooker<void, GLfloat *> lglIndexfv("glIndexfv");
Hooker<void, GLint *> lglIndexiv("glIndexiv");
Hooker<void, GLshort *> lglIndexsv("glIndexsv");
Hooker<void, GLubyte *> lglIndexubv("glIndexubv");
Hooker<void, GLbyte, GLbyte, GLbyte> lglColor3b("glColor3b");
Hooker<void, GLdouble, GLdouble, GLdouble> lglColor3d("glColor3d");
Hooker<void, GLfloat, GLfloat, GLfloat> lglColor3f("glColor3f");
Hooker<void, GLint, GLint, GLint> lglColor3i("glColor3i");
Hooker<void, GLshort, GLshort, GLshort> lglColor3s("glColor3s");
Hooker<void, GLubyte, GLubyte, GLubyte> lglColor3ub("glColor3ub");
Hooker<void, GLuint, GLuint, GLuint> lglColor3ui("glColor3ui");
Hooker<void, GLushort, GLushort, GLushort> lglColor3us("glColor3us");
Hooker<void, GLbyte *> lglColor3bv("glColor3bv");
Hooker<void, GLdouble *> lglColor3dv("glColor3dv");
Hooker<void, GLfloat *> lglColor3fv("glColor3fv");
Hooker<void, GLint *> lglColor3iv("glColor3iv");
Hooker<void, GLshort *> lglColor3sv("glColor3sv");
Hooker<void, GLubyte *> lglColor3ubv("glColor3ubv");
Hooker<void, GLuint *> lglColor3uiv("glColor3uiv");
Hooker<void, GLushort *> lglColor3usv("glColor3usv");
Hooker<void, GLbyte *> lglColor4bv("glColor4bv");
Hooker<void, GLdouble *> lglColor4dv("glColor4dv");
Hooker<void, GLfloat *> lglColor4fv("glColor4fv");
Hooker<void, GLint *> lglColor4iv("glColor4iv");
Hooker<void, GLshort *> lglColor4sv("glColor4sv");
Hooker<void, GLubyte *> lglColor4ubv("glColor4ubv");
Hooker<void, GLuint *> lglColor4uiv("glColor4uiv");
Hooker<void, GLushort *> lglColor4usv("glColor4usv");
Hooker<void, GLdouble> lglTexCoord1d("glTexCoord1d");
Hooker<void, GLfloat> lglTexCoord1f("glTexCoord1f");
Hooker<void, GLint> lglTexCoord1i("glTexCoord1i");
Hooker<void, GLshort> lglTexCoord1s("glTexCoord1s");
Hooker<void, GLdouble, GLdouble> lglTexCoord2d("glTexCoord2d");
Hooker<void, GLfloat, GLfloat> lglTexCoord2f("glTexCoord2f");
Hooker<void, GLint, GLint> lglTexCoord2i("glTexCoord2i");
Hooker<void, GLshort, GLshort> lglTexCoord2s("glTexCoord2s");
Hooker<void, GLdouble, GLdouble, GLdouble> lglTexCoord3d("glTexCoord3d");
Hooker<void, GLfloat, GLfloat, GLfloat> lglTexCoord3f("glTexCoord3f");
Hooker<void, GLint, GLint, GLint> lglTexCoord3i("glTexCoord3i");
Hooker<void, GLshort, GLshort, GLshort> lglTexCoord3s("glTexCoord3s");
Hooker<void, GLdouble, GLdouble, GLdouble, GLdouble> lglTexCoord4d("glTexCoord4d");
Hooker<void, GLfloat, GLfloat, GLfloat, GLfloat> lglTexCoord4f("glTexCoord4f");
Hooker<void, GLint, GLint, GLint, GLint> lglTexCoord4i("glTexCoord4i");
Hooker<void, GLshort, GLshort, GLshort, GLshort> lglTexCoord4s("glTexCoord4s");
Hooker<void, GLdouble *> lglTexCoord1dv("glTexCoord1dv");
Hooker<void, GLfloat *> lglTexCoord1fv("glTexCoord1fv");
Hooker<void, GLint *> lglTexCoord1iv("glTexCoord1iv");
Hooker<void, GLshort *> lglTexCoord1sv("glTexCoord1sv");
Hooker<void, GLdouble *> lglTexCoord2dv("glTexCoord2dv");
Hooker<void, GLfloat *> lglTexCoord2fv("glTexCoord2fv");
Hooker<void, GLint *> lglTexCoord2iv("glTexCoord2iv");
Hooker<void, GLshort *> lglTexCoord2sv("glTexCoord2sv");
Hooker<void, GLdouble *> lglTexCoord3dv("glTexCoord3dv");
Hooker<void, GLfloat *> lglTexCoord3fv("glTexCoord3fv");
Hooker<void, GLint *> lglTexCoord3iv("glTexCoord3iv");
Hooker<void, GLshort *> lglTexCoord3sv("glTexCoord3sv");
Hooker<void, GLdouble *> lglTexCoord4dv("glTexCoord4dv");
Hooker<void, GLfloat *> lglTexCoord4fv("glTexCoord4fv");
Hooker<void, GLint *> lglTexCoord4iv("glTexCoord4iv");
Hooker<void, GLshort *> lglTexCoord4sv("glTexCoord4sv");
Hooker<void, GLdouble, GLdouble> lglRasterPos2d("glRasterPos2d");
Hooker<void, GLfloat, GLfloat> lglRasterPos2f("glRasterPos2f");
Hooker<void, GLint, GLint> lglRasterPos2i("glRasterPos2i");
Hooker<void, GLshort, GLshort> lglRasterPos2s("glRasterPos2s");
Hooker<void, GLdouble, GLdouble, GLdouble> lglRasterPos3d("glRasterPos3d");
Hooker<void, GLfloat, GLfloat, GLfloat> lglRasterPos3f("glRasterPos3f");
Hooker<void, GLint, GLint, GLint> lglRasterPos3i("glRasterPos3i");
Hooker<void, GLshort, GLshort, GLshort> lglRasterPos3s("glRasterPos3s");
Hooker<void, GLdouble, GLdouble, GLdouble, GLdouble> lglRasterPos4d("glRasterPos4d");
Hooker<void, GLfloat, GLfloat, GLfloat, GLfloat> lglRasterPos4f("glRasterPos4f");
Hooker<void, GLint, GLint, GLint, GLint> lglRasterPos4i("glRasterPos4i");
Hooker<void, GLshort, GLshort, GLshort, GLshort> lglRasterPos4s("glRasterPos4s");
Hooker<void, GLdouble *> lglRasterPos2dv("glRasterPos2dv");
Hooker<void, GLfloat *> lglRasterPos2fv("glRasterPos2fv");
Hooker<void, GLint *> lglRasterPos2iv("glRasterPos2iv");
Hooker<void, GLshort *> lglRasterPos2sv("glRasterPos2sv");
Hooker<void, GLdouble *> lglRasterPos3dv("glRasterPos3dv");
Hooker<void, GLfloat *> lglRasterPos3fv("glRasterPos3fv");
Hooker<void, GLint *> lglRasterPos3iv("glRasterPos3iv");
Hooker<void, GLshort *> lglRasterPos3sv("glRasterPos3sv");
Hooker<void, GLdouble *> lglRasterPos4dv("glRasterPos4dv");
Hooker<void, GLfloat *> lglRasterPos4fv("glRasterPos4fv");
Hooker<void, GLint *> lglRasterPos4iv("glRasterPos4iv");
Hooker<void, GLshort *> lglRasterPos4sv("glRasterPos4sv");
Hooker<void, GLdouble, GLdouble, GLdouble, GLdouble> lglRectd("glRectd");
Hooker<void, GLfloat, GLfloat, GLfloat, GLfloat> lglRectf("glRectf");
Hooker<void, GLint, GLint, GLint, GLint> lglRecti("glRecti");
Hooker<void, GLshort, GLshort, GLshort, GLshort> lglRects("glRects");
Hooker<void, GLdouble *, GLdouble *> lglRectdv("glRectdv");
Hooker<void, GLfloat *, GLfloat *> lglRectfv("glRectfv");
Hooker<void, GLint *, GLint *> lglRectiv("glRectiv");
Hooker<void, GLshort *, GLshort *> lglRectsv("glRectsv");
Hooker<void, GLsizei> lglEdgeFlagPointer("glEdgeFlagPointer");
Hooker<void, GLenum> lglGetPointerv("glGetPointerv");
Hooker<void, GLint> lglArrayElement("glArrayElement");
Hooker<void, GLenum, GLint, GLsizei> lglDrawArrays("glDrawArrays");
Hooker<void, GLenum> lglShadeModel("glShadeModel");
Hooker<void, GLenum, GLenum, GLfloat> lglLightf("glLightf");
Hooker<void, GLenum, GLenum, GLint> lglLighti("glLighti");
Hooker<void, GLenum, GLfloat> lglLightModelf("glLightModelf");
Hooker<void, GLenum, GLint> lglLightModeli("glLightModeli");
Hooker<void, GLenum, GLfloat *> lglLightModelfv("glLightModelfv");
Hooker<void, GLenum, GLint *> lglLightModeliv("glLightModeliv");
Hooker<void, GLenum, GLenum, GLfloat> lglMaterialf("glMaterialf");
Hooker<void, GLenum, GLenum, GLint> lglMateriali("glMateriali");
Hooker<void, GLenum, GLenum, GLfloat *> lglMaterialfv("glMaterialfv");
Hooker<void, GLenum, GLenum, GLint *> lglMaterialiv("glMaterialiv");
Hooker<void, GLenum, GLenum, GLfloat *> lglGetMaterialfv("glGetMaterialfv");
Hooker<void, GLenum, GLenum, GLint *> lglGetMaterialiv("glGetMaterialiv");
Hooker<void, GLenum, GLenum> lglColorMaterial("glColorMaterial");
Hooker<void, GLfloat, GLfloat> lglPixelZoom("glPixelZoom");
Hooker<void, GLenum, GLfloat> lglPixelStoref("glPixelStoref");
Hooker<void, GLenum, GLint> lglPixelStorei("glPixelStorei");
Hooker<void, GLenum, GLfloat> lglPixelTransferf("glPixelTransferf");
Hooker<void, GLenum, GLint> lglPixelTransferi("glPixelTransferi");
Hooker<void, GLenum, GLfloat *> lglGetPixelMapfv("glGetPixelMapfv");
Hooker<void, GLenum, GLuint *> lglGetPixelMapuiv("glGetPixelMapuiv");
Hooker<void, GLenum, GLushort *> lglGetPixelMapusv("glGetPixelMapusv");
Hooker<void, GLenum, GLint, GLuint> lglStencilFunc("glStencilFunc");
Hooker<void, GLuint> lglStencilMask("glStencilMask");
Hooker<void, GLenum, GLenum, GLenum> lglStencilOp("glStencilOp");
Hooker<void, GLint> lglClearStencil("glClearStencil");
Hooker<void, GLenum, GLenum, GLdouble> lglTexGend("glTexGend");
Hooker<void, GLenum, GLenum, GLfloat> lglTexGenf("glTexGenf");
Hooker<void, GLenum, GLenum, GLint> lglTexGeni("glTexGeni");
Hooker<void, GLenum, GLenum, GLdouble *> lglTexGendv("glTexGendv");
Hooker<void, GLenum, GLenum, GLfloat *> lglTexGenfv("glTexGenfv");
Hooker<void, GLenum, GLenum, GLint *> lglTexGeniv("glTexGeniv");
Hooker<void, GLenum, GLenum, GLdouble *> lglGetTexGendv("glGetTexGendv");
Hooker<void, GLenum, GLenum, GLfloat *> lglGetTexGenfv("glGetTexGenfv");
Hooker<void, GLenum, GLenum, GLint *> lglGetTexGeniv("glGetTexGeniv");
Hooker<void, GLenum, GLenum, GLfloat> lglTexEnvf("glTexEnvf");
Hooker<void, GLenum, GLenum, GLint> lglTexEnvi("glTexEnvi");
Hooker<void, GLenum, GLenum, GLfloat *> lglTexEnvfv("glTexEnvfv");
Hooker<void, GLenum, GLenum, GLint *> lglTexEnviv("glTexEnviv");
Hooker<void, GLenum, GLenum, GLfloat *> lglGetTexEnvfv("glGetTexEnvfv");
Hooker<void, GLenum, GLenum, GLint *> lglGetTexEnviv("glGetTexEnviv");
Hooker<void, GLenum, GLenum, GLfloat> lglTexParameterf("glTexParameterf");
Hooker<void, GLenum, GLenum, GLint> lglTexParameteri("glTexParameteri");
Hooker<void, GLsizei, GLuint *> lglGenTextures("glGenTextures");
Hooker<void, GLsizei, GLuint *> lglDeleteTextures("glDeleteTextures");
Hooker<void, GLenum, GLuint> lglBindTexture("glBindTexture");
Hooker<GLboolean, GLuint> lglIsTexture("glIsTexture");
Hooker<void, GLenum, GLenum, GLdouble *> lglGetMapdv("glGetMapdv");
Hooker<void, GLenum, GLenum, GLfloat *> lglGetMapfv("glGetMapfv");
Hooker<void, GLenum, GLenum, GLint *> lglGetMapiv("glGetMapiv");
Hooker<void, GLdouble> lglEvalCoord1d("glEvalCoord1d");
Hooker<void, GLfloat> lglEvalCoord1f("glEvalCoord1f");
Hooker<void, GLdouble *> lglEvalCoord1dv("glEvalCoord1dv");
Hooker<void, GLfloat *> lglEvalCoord1fv("glEvalCoord1fv");
Hooker<void, GLdouble, GLdouble> lglEvalCoord2d("glEvalCoord2d");
Hooker<void, GLfloat, GLfloat> lglEvalCoord2f("glEvalCoord2f");
Hooker<void, GLdouble *> lglEvalCoord2dv("glEvalCoord2dv");
Hooker<void, GLfloat *> lglEvalCoord2fv("glEvalCoord2fv");
Hooker<void, GLint, GLdouble, GLdouble> lglMapGrid1d("glMapGrid1d");
Hooker<void, GLint, GLfloat, GLfloat> lglMapGrid1f("glMapGrid1f");
Hooker<void, GLint> lglEvalPoint1("glEvalPoint1");
Hooker<void, GLint, GLint> lglEvalPoint2("glEvalPoint2");
Hooker<void, GLenum, GLint, GLint> lglEvalMesh1("glEvalMesh1");
Hooker<void, GLenum, GLint, GLint, GLint, GLint> lglEvalMesh2("glEvalMesh2");
Hooker<void, GLenum, GLfloat> lglFogf("glFogf");
Hooker<void, GLenum, GLint> lglFogi("glFogi");
Hooker<void, GLenum, GLfloat *> lglFogfv("glFogfv");
Hooker<void, GLenum, GLint *> lglFogiv("glFogiv");
Hooker<void, GLsizei, GLenum, GLfloat *> lglFeedbackBuffer("glFeedbackBuffer");
Hooker<void, GLfloat> lglPassThrough("glPassThrough");
Hooker<void, GLsizei, GLuint *> lglSelectBuffer("glSelectBuffer");
Hooker<void> lglInitNames("glInitNames");
Hooker<void, GLuint> lglLoadName("glLoadName");
Hooker<void, GLuint> lglPushName("glPushName");
Hooker<void> lglPopName("glPopName");
Hooker<void, GLenum> lglBlendEquation("glBlendEquation");
Hooker<void, GLenum> lglResetHistogram("glResetHistogram");
Hooker<void, GLenum> lglResetMinmax("glResetMinmax");
Hooker<void, GLenum> lglActiveTexture("glActiveTexture");
Hooker<void, GLenum> lglClientActiveTexture("glClientActiveTexture");
Hooker<void, GLenum, GLint, GLenum, GLsizei, GLint, GLsizei> lglCompressedTexImage1D("glCompressedTexImage1D");
Hooker<void, GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei> lglCompressedTexImage2D("glCompressedTexImage2D");
Hooker<void, GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei> lglCompressedTexImage3D("glCompressedTexImage3D");
Hooker<void, GLenum, GLint, GLint, GLsizei, GLenum, GLsizei> lglCompressedTexSubImage1D("glCompressedTexSubImage1D");
Hooker<void, GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei> lglCompressedTexSubImage2D("glCompressedTexSubImage2D");
Hooker<void, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei> lglCompressedTexSubImage3D("glCompressedTexSubImage3D");
Hooker<void, GLenum, GLint> lglGetCompressedTexImage("glGetCompressedTexImage");
Hooker<void, GLenum, GLdouble> lglMultiTexCoord1d("glMultiTexCoord1d");
Hooker<void, GLenum, GLdouble *> lglMultiTexCoord1dv("glMultiTexCoord1dv");
Hooker<void, GLenum, GLfloat> lglMultiTexCoord1f("glMultiTexCoord1f");
Hooker<void, GLenum, GLfloat *> lglMultiTexCoord1fv("glMultiTexCoord1fv");
Hooker<void, GLenum, GLint> lglMultiTexCoord1i("glMultiTexCoord1i");
Hooker<void, GLenum, GLint *> lglMultiTexCoord1iv("glMultiTexCoord1iv");
Hooker<void, GLenum, GLshort> lglMultiTexCoord1s("glMultiTexCoord1s");
Hooker<void, GLenum, GLshort *> lglMultiTexCoord1sv("glMultiTexCoord1sv");
Hooker<void, GLenum, GLdouble, GLdouble> lglMultiTexCoord2d("glMultiTexCoord2d");
Hooker<void, GLenum, GLdouble *> lglMultiTexCoord2dv("glMultiTexCoord2dv");
Hooker<void, GLenum, GLfloat, GLfloat> lglMultiTexCoord2f("glMultiTexCoord2f");
Hooker<void, GLenum, GLfloat *> lglMultiTexCoord2fv("glMultiTexCoord2fv");
Hooker<void, GLenum, GLint, GLint> lglMultiTexCoord2i("glMultiTexCoord2i");
Hooker<void, GLenum, GLint *> lglMultiTexCoord2iv("glMultiTexCoord2iv");
Hooker<void, GLenum, GLshort, GLshort> lglMultiTexCoord2s("glMultiTexCoord2s");
Hooker<void, GLenum, GLshort *> lglMultiTexCoord2sv("glMultiTexCoord2sv");
Hooker<void, GLenum, GLdouble, GLdouble, GLdouble> lglMultiTexCoord3d("glMultiTexCoord3d");
Hooker<void, GLenum, GLdouble *> lglMultiTexCoord3dv("glMultiTexCoord3dv");
Hooker<void, GLenum, GLfloat, GLfloat, GLfloat> lglMultiTexCoord3f("glMultiTexCoord3f");
Hooker<void, GLenum, GLfloat *> lglMultiTexCoord3fv("glMultiTexCoord3fv");
Hooker<void, GLenum, GLint, GLint, GLint> lglMultiTexCoord3i("glMultiTexCoord3i");
Hooker<void, GLenum, GLint *> lglMultiTexCoord3iv("glMultiTexCoord3iv");
Hooker<void, GLenum, GLshort, GLshort, GLshort> lglMultiTexCoord3s("glMultiTexCoord3s");
Hooker<void, GLenum, GLshort *> lglMultiTexCoord3sv("glMultiTexCoord3sv");
Hooker<void, GLenum, GLdouble, GLdouble, GLdouble, GLdouble> lglMultiTexCoord4d("glMultiTexCoord4d");
Hooker<void, GLenum, GLdouble *> lglMultiTexCoord4dv("glMultiTexCoord4dv");
Hooker<void, GLenum, GLfloat, GLfloat, GLfloat, GLfloat> lglMultiTexCoord4f("glMultiTexCoord4f");
Hooker<void, GLenum, GLfloat *> lglMultiTexCoord4fv("glMultiTexCoord4fv");
Hooker<void, GLenum, GLint, GLint, GLint, GLint> lglMultiTexCoord4i("glMultiTexCoord4i");
Hooker<void, GLenum, GLint *> lglMultiTexCoord4iv("glMultiTexCoord4iv");
Hooker<void, GLenum, GLshort, GLshort, GLshort, GLshort> lglMultiTexCoord4s("glMultiTexCoord4s");
Hooker<void, GLenum, GLshort *> lglMultiTexCoord4sv("glMultiTexCoord4sv");
Hooker<void, GLclampf, GLboolean> lglSampleCoverage("glSampleCoverage");
Hooker<void, GLenum> lglActiveTextureARB("glActiveTextureARB");
Hooker<void, GLenum> lglClientActiveTextureARB("glClientActiveTextureARB");
Hooker<void, GLenum, GLdouble> lglMultiTexCoord1dARB("glMultiTexCoord1dARB");
Hooker<void, GLenum, GLdouble *> lglMultiTexCoord1dvARB("glMultiTexCoord1dvARB");
Hooker<void, GLenum, GLfloat> lglMultiTexCoord1fARB("glMultiTexCoord1fARB");
Hooker<void, GLenum, GLfloat *> lglMultiTexCoord1fvARB("glMultiTexCoord1fvARB");
Hooker<void, GLenum, GLint> lglMultiTexCoord1iARB("glMultiTexCoord1iARB");
Hooker<void, GLenum, GLint *> lglMultiTexCoord1ivARB("glMultiTexCoord1ivARB");
Hooker<void, GLenum, GLshort> lglMultiTexCoord1sARB("glMultiTexCoord1sARB");
Hooker<void, GLenum, GLshort *> lglMultiTexCoord1svARB("glMultiTexCoord1svARB");
Hooker<void, GLenum, GLdouble, GLdouble> lglMultiTexCoord2dARB("glMultiTexCoord2dARB");
Hooker<void, GLenum, GLdouble *> lglMultiTexCoord2dvARB("glMultiTexCoord2dvARB");
Hooker<void, GLenum, GLfloat, GLfloat> lglMultiTexCoord2fARB("glMultiTexCoord2fARB");
Hooker<void, GLenum, GLfloat *> lglMultiTexCoord2fvARB("glMultiTexCoord2fvARB");
Hooker<void, GLenum, GLint, GLint> lglMultiTexCoord2iARB("glMultiTexCoord2iARB");
Hooker<void, GLenum, GLint *> lglMultiTexCoord2ivARB("glMultiTexCoord2ivARB");
Hooker<void, GLenum, GLshort, GLshort> lglMultiTexCoord2sARB("glMultiTexCoord2sARB");
Hooker<void, GLenum, GLshort *> lglMultiTexCoord2svARB("glMultiTexCoord2svARB");
Hooker<void, GLenum, GLdouble, GLdouble, GLdouble> lglMultiTexCoord3dARB("glMultiTexCoord3dARB");
Hooker<void, GLenum, GLdouble *> lglMultiTexCoord3dvARB("glMultiTexCoord3dvARB");
Hooker<void, GLenum, GLfloat, GLfloat, GLfloat> lglMultiTexCoord3fARB("glMultiTexCoord3fARB");
Hooker<void, GLenum, GLfloat *> lglMultiTexCoord3fvARB("glMultiTexCoord3fvARB");
Hooker<void, GLenum, GLint, GLint, GLint> lglMultiTexCoord3iARB("glMultiTexCoord3iARB");
Hooker<void, GLenum, GLint *> lglMultiTexCoord3ivARB("glMultiTexCoord3ivARB");
Hooker<void, GLenum, GLshort, GLshort, GLshort> lglMultiTexCoord3sARB("glMultiTexCoord3sARB");
Hooker<void, GLenum, GLshort *> lglMultiTexCoord3svARB("glMultiTexCoord3svARB");
Hooker<void, GLenum, GLdouble, GLdouble, GLdouble, GLdouble> lglMultiTexCoord4dARB("glMultiTexCoord4dARB");
Hooker<void, GLenum, GLdouble *> lglMultiTexCoord4dvARB("glMultiTexCoord4dvARB");
Hooker<void, GLenum, GLfloat, GLfloat, GLfloat, GLfloat> lglMultiTexCoord4fARB("glMultiTexCoord4fARB");
Hooker<void, GLenum, GLfloat *> lglMultiTexCoord4fvARB("glMultiTexCoord4fvARB");
Hooker<void, GLenum, GLint, GLint, GLint, GLint> lglMultiTexCoord4iARB("glMultiTexCoord4iARB");
Hooker<void, GLenum, GLint *> lglMultiTexCoord4ivARB("glMultiTexCoord4ivARB");
Hooker<void, GLenum, GLshort, GLshort, GLshort, GLshort> lglMultiTexCoord4sARB("glMultiTexCoord4sARB");
Hooker<void, GLenum, GLshort *> lglMultiTexCoord4svARB("glMultiTexCoord4svARB");
Hooker<intmax_t, intmax_t> limaxabs("imaxabs");
Hooker<void, GLenum, GLenum> lglBlendEquationSeparateATI("glBlendEquationSeparateATI");
Hooker<void, Display *, GLXContext> lglXDestroyContext("glXDestroyContext");
Hooker<void, Display *, GLXDrawable> lglXSwapBuffers("glXSwapBuffers");
Hooker<void, Display *, GLXPixmap> lglXDestroyGLXPixmap("glXDestroyGLXPixmap");
Hooker<int, Display *, int *, int *> lglXQueryExtension("glXQueryExtension");
Hooker<int, Display *, int *, int *> lglXQueryVersion("glXQueryVersion");
Hooker<int, Display *, GLXContext> lglXIsDirect("glXIsDirect");
Hooker<GLXContext> lglXGetCurrentContext("glXGetCurrentContext");
Hooker<GLXDrawable> lglXGetCurrentDrawable("glXGetCurrentDrawable");
Hooker<void> lglXWaitGL("glXWaitGL");
Hooker<void> lglXWaitX("glXWaitX");
Hooker<void, Font, int, int, int> lglXUseXFont("glXUseXFont");
Hooker<char*, Display *, int> lglXQueryExtensionsString("glXQueryExtensionsString");
Hooker<char*, Display *, int, int> lglXQueryServerString("glXQueryServerString");
Hooker<char*, Display *, int> lglXGetClientString("glXGetClientString");
Hooker<Display*> lglXGetCurrentDisplay("glXGetCurrentDisplay");
Hooker<void, Display *, GLXWindow> lglXDestroyWindow("glXDestroyWindow");
Hooker<void, Display *, GLXPixmap> lglXDestroyPixmap("glXDestroyPixmap");
Hooker<void, Display *, GLXPbuffer> lglXDestroyPbuffer("glXDestroyPbuffer");
Hooker<GLXDrawable> lglXGetCurrentReadDrawable("glXGetCurrentReadDrawable");
Hooker<__GLXextFuncPtr, GLubyte *> lglXGetProcAddressARB("glXGetProcAddressARB");
Hooker<void, GLubyte *> lglXGetProcAddress("glXGetProcAddress");
Hooker<void*, GLsizei, GLfloat, GLfloat, GLfloat> lglXAllocateMemoryNV("glXAllocateMemoryNV");
Hooker<void> lglXFreeMemoryNV("glXFreeMemoryNV");
Hooker<int, Display *, GLXPbuffer, int> lglXBindTexImageARB("glXBindTexImageARB");
Hooker<int, Display *, GLXPbuffer, int> lglXReleaseTexImageARB("glXReleaseTexImageARB");
Hooker<int, Display *, GLXDrawable, int *> lglXDrawableAttribARB("glXDrawableAttribARB");
Hooker<int, Display *, GLXDrawable, float *> lglXGetFrameUsageMESA("glXGetFrameUsageMESA");
Hooker<int, Display *, GLXDrawable> lglXBeginFrameTrackingMESA("glXBeginFrameTrackingMESA");
Hooker<int, Display *, GLXDrawable> lglXEndFrameTrackingMESA("glXEndFrameTrackingMESA");
Hooker<int, Display *, GLXDrawable, int64_t *, int64_t *, float *> lglXQueryFrameTrackingMESA("glXQueryFrameTrackingMESA");
Hooker<int, unsigned> lglXSwapIntervalMESA("glXSwapIntervalMESA");
Hooker<int> lglXGetSwapIntervalMESA("glXGetSwapIntervalMESA");
Hooker<int, Display *, int, int, int, unsigned int *> lglXQueryRendererIntegerMESA("glXQueryRendererIntegerMESA");
Hooker<int, int, unsigned int *> lglXQueryCurrentRendererIntegerMESA("glXQueryCurrentRendererIntegerMESA");
Hooker<char*, Display *, int, int, int> lglXQueryRendererStringMESA("glXQueryRendererStringMESA");
Hooker<char*, int> lglXQueryCurrentRendererStringMESA("glXQueryCurrentRendererStringMESA");
