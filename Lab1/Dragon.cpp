#include "Dragon.h"

#include <GL/glut.h>
#include "main.h"

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
	for (int row = 0; row < xyzrows; row++)
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


void Dragon::findMinMax()
{
	double xMax = 0, xMin = 100, yMax = 0, yMin = 100, zMax = 0, zMin = 100;
	int row = 0;
	int count = 0;
	for (int row = 0; row < xyzrows; row++)
	{
		//Find min and max x
		if (dp[count] < xMin)
			xMin = dp[count];
		if (dp[count] > xMax)
			xMax = dp[count];

		//Find min and max y
		if (dp[count + 1] < yMin)
			yMin = dp[count + 1];
		if (dp[count + 1] > yMax)
			yMax = dp[count + 1];

		// Find min and max z
		if (dp[count + 2] < zMin)
			zMin = dp[count + 2];
		if (dp[count + 2] > zMax)
			zMax = dp[count + 2];
		count = count + 6;
	}
	cout << "For the Dragon: \n" << endl;
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
	double theta = (Globals::viewAngle / 2) / 180 * M_PI;
	double factor = tan(theta) * (abs(Globals::camZ) * 2) / (xMax - xMin);
	Matrix4 printScale;
	printScale.makeScale(factor, factor, factor);
	printScale.print("Scale matrix is: ");
	this->model2world = printScale * this->model2world;
}