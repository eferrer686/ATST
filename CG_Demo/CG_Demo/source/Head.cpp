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
	rotDir = 1;
}


Head::~Head()
{
}

void Head::draw() 
{
	glPushMatrix();
	{
		
		
		glTranslatef(x, y + 1.25, z+0.25);
		glRotatef(rotY, 0, 1, 0);

		glPushMatrix();
		{
			glScaled(0.9,.75, 1);
			glutWireCube(1.5);
		}

		//lateral Cannons
		glPushMatrix;
		{
			glTranslatef(x + 0.85, 0, -1);
			glutWireCylinder(.1, .7, 25, 2);
		
			glTranslatef(x - 1.7, 0, 0);
			glutWireCylinder(.1, .7, 25, 2);
		}
		glPopMatrix();

		//Front Cannons
		glPushMatrix();
		{
			glTranslatef(x-.1, y-.5, z-1.5);
			glutWireCylinder(.1, .7, 25, 2);
		
			glTranslatef(x + .2, 0, 0);
			glutWireCylinder(.1, .7, 25, 2);
		}
		glPopMatrix();
		
	}
	glPopMatrix();
}
	

void Head::update(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;

	//Rotation cycle from 70° to - 70°
	if (rotY > 50 || rotY < -50) { rotDir *= -1.0f; }
	rotY += 0.01*rotDir;
}


