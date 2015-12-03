#include <QtCore>

#include <cstdarg>

#include <dlfcn.h>
#include <execinfo.h>

#include <GL/glx.h>
#include <GL/glext.h>
#include <GL/glu.h>

#include <iostream>
#include <typeinfo>

#define QFXEXPORT(returned_type) extern "C" returned_type GLAPIENTRY

template<typename Return, typename... Args>
class Hooker{

public:
	typedef Return(*fType)(Args... arguments);
	fType f;
	Hooker(const char* hook);
	Return operator()(Args... arguments);
};
