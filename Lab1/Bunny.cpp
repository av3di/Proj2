#include "Bunny.h"

#include <GL/glut.h>
#include <math.h>
#include "main.h"

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

void Bunny::findMinMax()
{
	double xMax = 0, xMin = 100, yMax= 0, yMin= 100, zMax= 0, zMin = 100;
	int row = 0;
	int count = 0;
	for (int row = 0; row < 35947; row++)
	{
		//Find min and max x
		if (bp[count] < xMin)
			xMin = bp[count];
		if (bp[count] > xMax)
			xMax = bp[count];

		//Find min and max y
		if (bp[count+1] < yMin)
			yMin = bp[count+1];
		if (bp[count+1] > yMax)
			yMax = bp[count+1];

		// Find min and max z
		if (bp[count+2] < zMin)
			zMin = bp[count + 2];
		if (bp[count+2] > zMax)
			zMax = bp[count+2];
		count = count + 6;
	}

	cout << "For the Bunny: \n" << endl;
	cout << "Largest x value is: " << xMax << endl;
	cout << "Smallest x value is: " << xMin << endl;

	cout << "Largest y value is: " << yMax << endl;
	cout << "Smallest y value is: " << yMin << endl;

	cout << "Largest z value is: " << zMax << endl;
	cout << "Smallest z value is: " << zMin << "\n" << endl;

	// Fill the window

	// Translate
	double midx = (xMax + xMin) / 2;
	double midy = (yMax + yMin) / 2;
	double midz = (zMax + zMin) / 2;
	Matrix4 printTranslate;
	printTranslate.makeTranslate(midx * -1, midy * -1, midz * -1);
	printTranslate.print("Translate matrix is : ");
	cout << "\n " << endl;

	this->model2world = printTranslate * this->model2world;

	// Scale
	double factor = (tan((30 * M_PI) / 180) * 20) / (yMax - yMin);
	Matrix4 printScale;
	printScale.makeScale(factor, factor, factor);
	printScale.print("Scale matrix is: ");
	cout << "\n" << endl;
	this->model2world = printScale * this->model2world;
}