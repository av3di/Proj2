#ifndef _CUBE_H_
#define _CUBE_H_

#include "Matrix4.h"

class Cube
{
  protected:
    Matrix4 model2world;            // model matrix (transforms model coordinates to world coordinates)
    double angle;                   // rotation angle [degrees]
	bool counter;
  public:

    Cube();   // Constructor
    Matrix4& getMatrix();
    void spin(double);      // spin cube [degrees]
	//void changeSpinWay(bool);
	bool getCounter();
	void setCounter( bool );
	void Cube::translate(double, double, double);
	void Cube::scale(double, double, double);
	void Cube::rotate(double);
};

#endif

