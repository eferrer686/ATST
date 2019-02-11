#include "Body.h"

#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif

Body::Body()
{
	x = y = z = 0;
	r = g = b = 0.5;
}


Body::~Body()
{
}

void Body::draw() {
	//Rotate 90 deg neck
	glPushMatrix();
	{
		glTranslatef(0, 0, 0.25);
		glTranslatef(0,0.666,0);
		glRotatef(90, 1, 0, 0);
		glutWireCylinder(.25,.5,20,2);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(x, y, z + 0.5);
		glScaled(1, 0.4, 1.5);
		glutWireCube(1);
	}
	glPopMatrix();
}
void Body::update(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}