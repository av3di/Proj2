#include "Bunny.h"

#include <GL/glut.h>

using namespace std;

Bunny::Bunny()
{
	parseBunnyFile();  // Fill in bp[] with all the data to draw the bunny
}


Bunny::~Bunny()
{
}

void Bunny::draw()
{
	glBegin(GL_POINTS);
	Vector3 normal; //35947
	int count = 0;
	for (int row = 0; row < 35947; row++)
	{
		normal.setX(bp[count + 3]);
		normal.setY(bp[count + 4]);
		normal.setZ(bp[count + 5]);
		normal.normalize();

		glNormal3d(normal.getX(), normal.getY(), normal.getZ());
		glVertex3d(bp[count], bp[count + 1], bp[count + 2]);

		count = count + 6;
	}
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void Bunny::parseBunnyFile()
{
	// Create pointer to the xyz bunny file
	FILE * xyzf;
	double d;
	xyzf = fopen("bunny.xyz", "r");

	// Bunny has 215,682 doubles
	for (int count = 0; count < 215682; count++)
	{
		fscanf(xyzf, "%lf", &d);
		bp[count] = d;
	}
}
