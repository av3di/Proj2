#include "Dragon.h"

#include <GL/glut.h>

using namespace std;

Dragon::Dragon()
{
	parseDragonFile();  // Fill in dp[] with all the data to draw the dragon
}


Dragon::~Dragon()
{
}

void Dragon::parseDragonFile()
{
	// Create pointer to the xyz bunny file
	FILE * xyzf;
	double d;
	xyzf = fopen("dragon.txt", "r");

	// Dragon has 601,500 doubles
	for (int count = 0; count < 601500; count++)
	{
		fscanf(xyzf, "%lf", &d);
		dp[count] = d;
	}

}

void Dragon::draw()
{
	Vector3 normal;
	glBegin(GL_POINTS);
	int count = 0;
	for (int row = 0; row < 100250; row++)
	{
		normal.setX(dp[count + 3]);
		normal.setY(dp[count + 4]);
		normal.setZ(dp[count + 5]);
		normal.normalize();
		glNormal3d(normal.getX(), normal.getY(), normal.getZ());
		glVertex3d(dp[count], dp[count + 1], dp[count + 2]);
		count = count + 6;
	}
	glEnd();
	glFlush();
	glutSwapBuffers();
}


