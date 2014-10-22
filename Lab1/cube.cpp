#include "Cube.h"
#include "Matrix4.h"

using namespace std;


Cube::Cube()
{
 // spinClockwise = true;
  angle = 0.0;
  counter = true;
}

Matrix4& Cube::getMatrix()
{
  return model2world;
}

void Cube::rotate(double a)
{
	Matrix4 *rotation = new Matrix4();
	rotation->makeRotateZ(a);
	model2world = *rotation * model2world;
}
void Cube::scale(double x, double y, double z)
{
	Matrix4 *scaling = new Matrix4;
	scaling->makeScale(x, y, z);
	this->model2world = *scaling * this->model2world;
}

void Cube::translate(double x, double y, double z)
{
	Matrix4 *translation = new Matrix4();
	translation->makeTranslate(x, y, z);
	this->model2world = *translation * this->model2world;
}

void Cube::spin(double deg)   // deg is in degrees
{	
	Matrix4 testing;
	testing.makeRotateY(counter ? deg : -1 * deg);
	angle += deg;
	if (angle > 360.0 || angle < -360.0) angle = 0.0;
	model2world = model2world * testing; // This creates the matrix to rotate the cube}
	
}

bool Cube::getCounter()
{
	return this->counter;
}

void Cube::setCounter(bool c)
{
	this->counter = c;
}
