#ifndef _HOUSE_H_
#define _HOUSE_H_

#include <stdlib.h>
#include <array>
#include "Matrix4.h"

class House
{
private:
	int nVerts;
	std::array<float, 126> vertices;
	std::array<float, 126> colors;
	std::array<int, 60> indices;
	Matrix4 model2world;

public:
	House();
	~House();
	float getVertices(int i);
	float getColors(int i);
	int getIndices(int i);
	Matrix4& getMatrix();
};

#endif