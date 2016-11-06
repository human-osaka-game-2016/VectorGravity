#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Obj.h"

class BackGround : public Obj
{
private:

	Texture m_texture;

public:

	BackGround();
	~BackGround();

	virtual void Draw();
};

#endif 