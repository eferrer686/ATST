#pragma once
class Atst
{
public:
	Atst();
	~Atst();

	float x, y, z;
	float r, g, b;
	
	float vel;

	float rotY;


	void draw();
	void update();
};

