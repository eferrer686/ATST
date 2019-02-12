#pragma once
class Leg
{
public:
	Leg();
	~Leg();

	Leg(float dir);
	Leg(float dir, float _rotXL1);
	Leg(float dir, float _rotXL1, bool left);

	float x, y, z;
	float r, g, b;
	bool left;

	float dirLeg;

	float rotXL1, rotXL2, rotXL3, rotXFeet;

	void draw();
	void update(float _x, float _y, float _z);

	
};

