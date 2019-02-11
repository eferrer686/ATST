#include "Head.h"

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



Head::Head()
{
	rotY = 0;
}


Head::~Head()
{
}

void Head::draw() 
{
	glPushMatrix();
	{
		glTranslatef(x, y + 1.25, z+0.25);
		glScaled(0.9,.75, 1);
		glutWireCube(1.5);
		glPushMatrix;
		{
			glTranslatef(x + 1, y, z-.8);
			glutWireCylinder(.1, .7, 25, 2);
		}
		//glPopMatrix();
		glPushMatrix;
		{
			glTranslatef(x - 2, y, z);
			glutWireCylinder(.1, .7, 25, 2);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(x - .1, y + .60, z - 1.1);
			glutWireCylinder(.1, .7, 25, 2);
		}
		glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(x + .1, y + .60, z - 1.1);
			glutWireCylinder(.1, .7, 25, 2);
		}
		
	}
	glPopMatrix();
}
	

void Head::update(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
	glPushMatrix();
	{
		glRotatef(rotY, _x, _y, _z);
	}
	glPopMatrix();
	
}

float Head::getRotY()
{
	return rotY;
}

void Head::setRotY(float _rotY)
{
	rotY = _rotY;
}

