#pragma once
class Leg
{
public:
	Leg();
	~Leg();

	Leg(float dir);

	float x, y, z;
	float r, g, b;

	float dirLeg;

	float rotXL1, rotXL2, rotXL3, rotXFeet;

	void draw();
	void update(float _x, float _y, float _z);

	
};

