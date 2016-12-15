#ifndef TANK_H
#define TANK_H

#include"Enemy.h"

class InputKey;

#define TANKWIDTH  256
#define TANKHEIGHT 192
#define MOVESPEED 10

class Tank : public Enemy
{
public:
	Tank();
	~Tank();

	virtual void Control();
	virtual void Draw();

private:

	InputKey* m_pInputKey;
};

#endif // !TANK_H