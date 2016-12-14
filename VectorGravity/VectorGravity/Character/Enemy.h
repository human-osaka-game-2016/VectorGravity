#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();

	virtual void Control();
	virtual void Draw();

private:

};

#endif // !ENEMY_H
