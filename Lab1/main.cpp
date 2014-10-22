#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glut.h>

#include "Window.h"
#include "Cube.h"
#include "Matrix4.h"
#include "main.h"
#include "vector3.h"
#include "Vector4.h"
#include "Camera.h"

using namespace std;

namespace Globals
{
  Cube cube;
  //Camera cam;
};

int main(int argc, char *argv[])
{
  float specular[]  = {1.0, 1.0, 1.0, 1.0};
  float shininess[] = {100.0};
  float position[]  = {0.0, 10.0, 1.0, 0.0};	// lightsource position
  
  glutInit(&argc, argv);      	      	      // initialize GLUT
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);   // open an OpenGL context with double buffering, RGB colors, and depth buffering
  glutInitWindowSize(Window::width, Window::height);      // set initial window size
  glutCreateWindow("OpenGL Cube");    	      // open window and set window title

  glEnable(GL_DEPTH_TEST);            	      // enable depth buffering
  glClear(GL_DEPTH_BUFFER_BIT);       	      // clear depth buffer
  glClearColor(0.0, 0.0, 0.0, 0.0);   	      // set clear color to black
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);  // set polygon drawing mode to fill front and back of each polygon
  glDisable(GL_CULL_FACE);     // disable backface culling to render both sides of polygons
  glShadeModel(GL_SMOOTH);             	      // set shading to smooth
  glMatrixMode(GL_PROJECTION); 
  
  // Generate material properties:
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);
  
  // Generate light source:
  glLightfv(GL_LIGHT0, GL_POSITION, position);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glDisable(GL_LIGHTING);
  
  // Install callback functions:
  glutDisplayFunc(Window::displayCallback);
  glutReshapeFunc(Window::reshapeCallback);
  glutIdleFunc(Window::idleCallback);

  glutKeyboardFunc(Window::processNormalKeys);
    
  // Initialize cube matrix:
  Globals::cube.getMatrix().identity();
  //Globals::cam.getMatrix().identity();
  glutMainLoop();

	/* Test Vector3 class */
	/*
	Vector3 *test1 = new Vector3(5, -2, 9);
	Vector3 *test2 = new Vector3(2, 10, 1);
	(*test1 - *test2).print("test1 - test2 is: ");
	(*test1 + *test2).print("test1 + test2 is: ");
	test1->negate();
	test1->print("test1 negated is: ");
	test2->scale(3);
	test2->print("test2 scaled by 3 is: ");
	std::cout << "dot: " << test1->dot(*test2) << std::endl;
	Vector3 cross = test1->cross(*test2);
	cross.print("Cross vector is: ");
	test1->print("test1 vector is: ");
	std::cout << "test1 og length: " << test1->length() << std::endl;
	test1->normalize();
	std::cout << "test1 length after normalize: " << test1->length() << std::endl;
	*/
	/* Test Vector4 class */
	/*
	Vector4 *test1 = new Vector4(5, -2, 9, 21);
	Vector4 *test2 = new Vector4(2, 10, 1, 25);
	test1->print("test1 is: ");
	test2->print("test2 is: ");
	(*test1 - *test2).print("test1 - test2 is: ");
	(*test1 + *test2).print("test1 + test2 is: ");
	test1->dehomogenize();
	test1->print("test1 dehomogenied is: ");
	system("pause");
	*/
	
  return 0;
}

