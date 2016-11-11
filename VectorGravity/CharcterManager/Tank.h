#ifndef TANK_H
#define TANK_H

#include "Character.h"
#include "Collision.h"

#define TANKWIDTH  512
#define TANKHEIGHT 256
#define BLOWSPEED 20

class Tank : public Character
{
public:
	Tank();
	~Tank();

	virtual void Control();
	virtual void Draw();
	virtual void Attack();
	virtual void Move();

	RECT GetTankRect()
	{
		return m_tank;
	}

private:

	InputKeyBorad* m_pInputKey;
	Texture m_texture;

	RECT m_tank;

	bool m_hits;
	int m_hitCount;
};

#endif // !TANK_H
