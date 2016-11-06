#ifndef ROBO_H
#define ROBO_H

#include "Obj.h"
#include "Collision.h"


class Robo : public Obj
{
public:

	/*void SetRect(RECT robo)
	{
		m_robo = robo;
	}*/
	
	RECT GetPlayerRect()
	{
		return m_robo;
	}

	Robo();
	~Robo();

	virtual void Control();
	virtual void Draw();

private:

	InputKeyBorad* m_inputkeydevice;
	Texture m_texture;
	//Collision* m_collision;

	RECT m_robo;

	bool m_hit;

	long width;
	long height;

};

#endif