#ifndef TANK_H
#define TANK_H

#include "Character.h"
#include "../CollisionManager/Collision.h"
#include <DirectInput.h>

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
		return m_hitRect;
	}

private:

	InputKeyBorad* m_pInputKey;

	RECT m_tank;
	RECT m_hitRect;

	bool m_hits;
	int m_hitCount;
};

#endif // !TANK_H
