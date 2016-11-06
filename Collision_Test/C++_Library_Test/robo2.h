#ifndef ROBO2_H
#define ROBO2_H

#include "Obj.h"
#include "Collision.h"

class Robo2 : public Obj
{
public:

	/*void SetRect(RECT robo2)
	{
		m_robo2 = robo2;
	}*/

	RECT GetEnemyRect()
	{
		return m_robo2;
	}


	Robo2();
	~Robo2();

	virtual void Control();
	virtual void Draw();

private:

	Texture m_texture;

	RECT m_robo2;

	// サイズ計算
	long width;
	long height;


};

#endif ROBO2_H