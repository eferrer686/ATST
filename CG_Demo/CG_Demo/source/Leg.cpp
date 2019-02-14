#include "Leg.h"

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

#include <stdio.h>
#include <math.h>

#endif



Leg::Leg()
{
	x = y = z = 0;
	r = g = b = 0.5;

	dirLeg = 1;

	rotXL1 = -80;
	rotXL2 = 110;
	rotXL3 = 30;
	rotXFeet = 30;
}

Leg::Leg(float dir)
{
	x = y = z = 0;
	r = g = b = 0.5;

	dirLeg = dir;
	left = true;
	rotXL1 = -80;
	rotXL2 = 110;
	rotXL3 = 30;
	rotXFeet = 30;
}
Leg::Leg(float dir, float _rotXL1)
{
	x = y = z = 0;
	r = g = b = 0.5;

	dirLeg = dir;
	left = true;
	rotXL1 = _rotXL1;
	rotXL2 = 110;
	rotXL3 = 30;
	rotXFeet = 30;
}

Leg::Leg(float dir, float _rotXL1, bool _left)
{
	x = y = z = 0;
	r = g = b = 0.5;

	dirLeg = dir;
	left = _left;
	rotXL1 = _rotXL1;
	rotXL2 = 110;
	rotXL3 = 30;
	rotXFeet = 30;
}


Leg::~Leg()
{
}

void Leg::draw() {
	glPushMatrix();
	{
		//Rotation and transate
		glRotatef(rotXL1, 1, 0, 0);
		glTranslatef(x, y - 1, z);

		//Matrix for scale and draw
		glPushMatrix();
		{
			glScalef(0.2,2,0.2);
			glutWireCube(1);
		}
		glPopMatrix();

		//Matrix for second leg
		glPushMatrix();
		{
			//Rotation and translation - for second leg
			glTranslatef(0, y - 1, 0);
			glRotatef(rotXL2, 1, 0, 0);
			glTranslatef(0, y-1, 0);
			
			
			//Matrix for scale and draw - for second leg
			glPushMatrix();
			{
				glScalef(0.2, 2, 0.2);
				glutWireCube(1);
				
			}
			glPopMatrix();

			//Matrix for third leg
			glPushMatrix();
			{
				//Rotation and translation - for third leg
				glTranslatef(0, y - 1, 0);
				glRotatef(rotXL3, 1, 0, 0);
				glTranslatef(0, y - 0.15, 0);
				//Matrix for scale and draw - for third leg
				glPushMatrix();
				{
					glScalef(0.2, 1, 0.2);
					glutWireCube(1);
				}
				glPopMatrix();

				//Matrix for feet
				glPushMatrix();
				{
					//Rotation and translation - for feet
					glTranslatef(0, y - 0.4, 0);
					glRotatef(rotXFeet, 1, 0, 0);
					glTranslatef(0, y - 0.4, 0);
					//Matrix for scale and draw - for feet
					glPushMatrix();
					{
						glScalef(0.5, 0.8, 0.2);
						glutWireCube(1);
					}
					glPopMatrix();
				}
				glPopMatrix();
			}
			glPopMatrix();
		}
		glPopMatrix();

	}
	glPopMatrix();
}


void Leg::update(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
	
	if (rotXL1 <= -100 || rotXL1 >= -60) {
		dirLeg *= -1;
	}
	rotXL1 += 0.09*dirLeg;
	rotXL2 +=  0.12*dirLeg;
	rotXL3 += 0.15*dirLeg;
	rotXFeet -= .33*dirLeg;
	
}