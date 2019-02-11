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

#include "Atst.h"

#include "Body.h"
#include "Leg.h"
#include "Head.h"



Body* body;
Leg* leg[2];

Head* head;

Atst::Atst()
{
	x = y = z = 0;
	r = g = b = 0.5;

	vel = 0;

	rotY = 0;

	body = new Body();

	head = new Head();
	
	leg[0] = new Leg();
	leg[1] = new Leg();
}


Atst::~Atst()
{
}

void Atst::draw() {


	glColor3f(r, g, b);

	glRotatef(rotY, 0, 1, 0);

	//Head
	head->draw();

	//Body = Leg Axis (Base between head and legs)
	body->draw();

	//Legs
	for (int i = 0; i < 2; i++) {
		leg[i] -> draw();
	}
}

void Atst::update() {
	float alfa = head->getRotY();
	if (alfa >=0.0f && (alfa<=30.0f))
	{
		head->setRotY(alfa+.1);
	}
	else if (alfa <= 0.0f && (alfa <= -30.0f)) {
		head->setRotY(alfa - .1);
	}
	head->update(x, y, z);
	body->update(x, y, z);

	leg[0] -> update(x-.5,y,z);
	leg[1] -> update(x+.5,y,z);

	rotY += 0.01;
	
}