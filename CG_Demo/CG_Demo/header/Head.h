#pragma once
class Head
{
public:
	Head();
	~Head();

	float x, y, z;
	float r, g, b;
	float rotY;

	float rotDir;

	void draw();
	void update(float _x, float _y, float _z);
	float getRotY();
	void setRotY(float _rotY);

};

