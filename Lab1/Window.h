#ifndef _WINDOW_H_
#define _WINDOW_H_


class Window	  // OpenGL output window related routines
{
  public:
    static int width, height, wm; 	            // window size

    static void idleCallback(void);
    static void reshapeCallback(int, int);
    static void displayCallback(void);
	static void processNormalKeys(unsigned char key, int x, int y);
	static void processSpecialKeys(int key, int x, int y);
	static void drawCube();
	static void drawHouse();
	static void parsefile();
};

#endif

