#pragma once
class Head
{
public:
	Head();
	~Head();

	float x, y, z;
	float r, g, b;

	void draw();
	void update(float _x, float _y, float _z);

};

