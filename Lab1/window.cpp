
#include <iostream>
#include <GL/glut.h>

#include "Window.h"
#include "Cube.h"
#include "Matrix4.h"
#include "main.h"
#include "Camera.h"
#include "House.h"

using namespace std;

int Window::width  = 512;   // set window width in pixels here
int Window::height = 512;   // set window height in pixels here
int Window::wm = 1;  // If 1, show cube, 2->show 1st cam, 3->show 2nd cam



//----------------------------------------------------------------------------
// Callback method called when system is idle.
void Window::idleCallback()
{
	Globals::cube.spin(0.1);   // rotate cube; if it spins too fast try smaller values and vice versa
	displayCallback();         // call display routine to show the cube
}

//----------------------------------------------------------------------------

void Window::processSpecialKeys(int key, int x, int y){
	glMatrixMode(GL_MODELVIEW);  // make sure we're in Modelview mode
	switch (key){
	case GLUT_KEY_F1:
		Window::wm = 1;
		break;
	case GLUT_KEY_F2:
		Window::wm = 2;
		break;
	case GLUT_KEY_F3:
		Window::wm = 3;
		break;
	}
}


// Callback method called by GLUT when graphics window is resized by the user
void Window::reshapeCallback(int w, int h)
{
  cerr << "Window::reshapeCallback called" << endl;
  width = w;
  height = h;
  glViewport(0, 0, w, h);  // set new viewport size
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, double(width)/(double)height, 1.0, 1000.0); // set perspective projection viewing frustum
  glTranslatef(0, 0, -20);    // move camera back 20 units so that it looks at the origin (or else it's in the origin)
  glMatrixMode(GL_MODELVIEW);
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when window readraw is necessary or when glutPostRedisplay() was called.
void Window::displayCallback()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);  // make sure we're in Modelview mode
  if (wm == 1)
  {
	  glEnable(GL_LIGHTING);
	  glLoadMatrixd(Globals::cube.getMatrix().getPointer());
	  Window::drawCube();
  }
  else if (wm == 2)
  {
	  glDisable(GL_LIGHTING);
	  glLoadMatrixd(Globals::cam1.getMatrix().getPointer());
	  Window::drawHouse();
  }
  else
  {
	  glDisable(GL_LIGHTING);
	  glLoadMatrixd(Globals::cam2.getMatrix().getPointer());
	  Window::drawHouse();
  }
 
  // Get the object2world matrix
 // Matrix4 houseMat = Globals::h->getMatrix();
 // Multiply it into the current opengl matrix
 // glLoadMatrixd((houseMat * Globals::cam1.getMatrix()).getPointer());

}

void Window::parsefile()
{
	// Create pointer to the xyz bunny file
	// 
}

void Window::processNormalKeys(unsigned char key, int x, int y){
	Matrix4 *mytest;
	mytest = &(Globals::cube.getMatrix());
	switch (key){
	case 27:
		exit(0);
		break;
	case 't':
		Globals::cube.setCounter(!Globals::cube.getCounter());
		break;
	case 'x':
		Globals::cube.translate(-1.0, 0.0, 0.0);
		break;
	case 'X':
		Globals::cube.translate(1.0, 0.0, 0.0);
		break;
	case 'Z':
		Globals::cube.translate(0.0, 0.0, 1.0);
		break;
	case 'z':
		Globals::cube.translate(0.0, 0.0, -1.0);
		break;
	case 'y':
		Globals::cube.translate(0.0, -1.0, 0.0);
		break;
	case 'Y':
		Globals::cube.translate(0.0, 1.0, 0.0);
		break;
	case 's':
		Globals::cube.scale(0.5, 0.5, 0.5);
		break;
	case'S':
		Globals::cube.scale(1.5, 1.5, 1.5);
		break;
	case 'o':
		Globals::cube.rotate(10);
		break;
	case 'O':
		Globals::cube.rotate(-10);
		break;
	case 'r':
		mytest->makeRotateY(1.0);
		break;
	}
}

void Window::drawCube()
{
	// Draw all six faces of the cube:
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);		// This makes the cube green; the parameters are for red, green and blue.
	// To change the color of the other faces you will need to repeat this call before each face is drawn.
	// Draw front face:
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(-5.0,  5.0,  5.0);
	glVertex3f( 5.0,  5.0,  5.0);
	glVertex3f( 5.0, -5.0,  5.0);
	glVertex3f(-5.0, -5.0,  5.0);

	// Draw left side:
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-5.0,  5.0,  5.0);
	glVertex3f(-5.0,  5.0, -5.0);
	glVertex3f(-5.0, -5.0, -5.0);
	glVertex3f(-5.0, -5.0,  5.0);

	// Draw right side:
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f( 5.0,  5.0,  5.0);
	glVertex3f( 5.0,  5.0, -5.0);
	glVertex3f( 5.0, -5.0, -5.0);
	glVertex3f( 5.0, -5.0,  5.0);

	// Draw back face:
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-5.0,  5.0, -5.0);
	glVertex3f( 5.0,  5.0, -5.0);
	glVertex3f( 5.0, -5.0, -5.0);
	glVertex3f(-5.0, -5.0, -5.0);

	// Draw top side:
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(-5.0,  5.0,  5.0);
	glVertex3f( 5.0,  5.0,  5.0);
	glVertex3f( 5.0,  5.0, -5.0);
	glVertex3f(-5.0,  5.0, -5.0);

	// Draw bottom side:
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-5.0, -5.0, -5.0);
	glVertex3f( 5.0, -5.0, -5.0);
	glVertex3f( 5.0, -5.0,  5.0);
	glVertex3f(-5.0, -5.0,  5.0);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void Window::drawHouse()
{
	glBegin(GL_TRIANGLES);

	int len = 60;
	int index = -1;
	float x;
	float y;
	float z;
	float r;
	float g;
	float b;

	for (int i = 0; i < len; i++)
	{
		index = 3 * Globals::h.getIndices(i);
		r = Globals::h.getColors(index);
		g = Globals::h.getColors(index + 1);
		b = Globals::h.getColors(index + 2);
		x = Globals::h.getVertices(index);
		y = Globals::h.getVertices(index + 1);
		z = Globals::h.getVertices(index + 2);
		glColor3f(r, g, b);                    //Set color
		glVertex3f(x, y, z); //Pass vertex to OpenGL
	}

	glEnd();
	glFlush();
	glutSwapBuffers();
}