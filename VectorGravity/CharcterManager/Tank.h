#ifndef TANK_H
#define TANK_H

#include"Character.h"

#define TankWidth  512
#define TankHeight 256

class Tank : public Character
{
public:
	Tank();
	~Tank();

	virtual void Control();
	virtual void Draw();
	virtual void Attack();
	virtual void Move();

private:

protected:
	Texture m_texture;

	RECT m_tank;

};

#endif TANK_H
