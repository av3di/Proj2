#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "Model.h"


class Dragon : public Model
{
protected:
	double dp[601500];

public:
	Dragon();
	~Dragon();
	virtual void draw();
	void parseDragonFile();
	void findMinMax();
};

#endif

