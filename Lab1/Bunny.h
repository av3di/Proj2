#ifndef _BUNNY_H_
#define _BUNNY_H_

#include "Model.h"


class Bunny : public Model
{
protected:
	double bp[215682];
	int xyzrows = 35947;
	int bpLength = 215682;

public:
	Bunny();
	~Bunny();
	virtual void draw();
	void parseBunnyFile();
	void findMinMax();
};

#endif

