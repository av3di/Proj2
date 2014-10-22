#include "Camera.h"


Camera::Camera() : e(0, 0, 0), d(0, 0, 0), up(0, 0, 0), c()
{
}


Camera::~Camera()
{
}

GLdouble* Camera::getGLMatrix()
{
	GLdouble gla[16];
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			gla[row + 4 * col] = c.get(row, col);
		}
	}
	return gla;
}

Matrix4 Camera::getMatrix()
{
	return c;
}

void Camera::sete(double x, double y, double z)
{
	Vector3 *a = new Vector3(x, y, z); //w 1 for point
	e = *a;
	c.setRow(0, x, y, z, 1);
}
void Camera::setd(double x, double y, double z)
{
	Vector3 *a = new Vector3(x, y, z);
	d = *a;
	c.setRow(1, x, y, z, 1);
}
void Camera::setup(double x, double y, double z)
{
	Vector3 *a = new Vector3(x, y, z);
	up = *a;
	c.setRow(2, x, y, z, 0);
}