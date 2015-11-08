/*
 * eve.c: Simple LD_PRELOAD injection for OpenGL applications.
 *
 * gcc -std=c99 -Wall -Werror -m32 -O0 -fpic -shared -ldl -lGL -o eve.so eve.c
 *
 * How to use with WINE:
 *   wineserver -k
 *   export LD_PRELOAD=/path/to/eve.so
 *   wine Wow.exe
 *
 */

/* These libraries are necessary for the hook */
#include <dlfcn.h>
#include <stdlib.h>
#include <GL/gl.h>

/* "Injected" stuff */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <iostream>

void doevil();

void* handle;

void glClear(GLbitfield mask){
	static void  (*lib_glClear)(GLbitfield mask) = NULL;
	char* errorstr;
	if(!lib_glClear) {
		/* Load real libGL */
		handle = dlopen("/usr/lib/fglrx/libGL.so", RTLD_LAZY);
		if(!handle) {
			fputs(dlerror(), stderr);
			exit(1);
		}

		/* Fetch pointer of real glClear() func */

		*(void**)(&lib_glClear) = dlsym(handle, "glClear");
		if( (errorstr = dlerror()) != NULL ) {
			fprintf(stderr, "dlsym fail: %s\n", errorstr);
			exit(1);
		}
	}

	/* Woot */
	doevil();

	/* Call real glClear() */
	(*lib_glClear)(mask);
}

struct MyVertex
{
	float x, y, z;        //Vertex
	float nx, ny, nz;     //Normal
	float s0, t0;         //Texcoord0
};

/* Here be dragons */
void doevil() {
	static int framecnt = 0;
	framecnt++;

	printf("doevil(), frame %d... \n", framecnt);
}
