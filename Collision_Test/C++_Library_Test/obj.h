#ifndef OBJ_H
#define OBJ_H

#include <DirectDrawTexture.h>
#include <DirectInput.h>
//#include "Collision.h"

#define MOVESPEED 10;
#define NOSPEED 0;

class Obj
{
protected:

public:

	Obj();
	~Obj();

	virtual void Control();
	virtual void Draw() = 0;

	//Collision* collision;
};

#endif 