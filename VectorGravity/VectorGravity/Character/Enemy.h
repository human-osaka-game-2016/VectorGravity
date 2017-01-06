#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

enum EnemySound
{
	ACTIV_TRIGGER,
	BLOW_WAY,
	ENEMY_REFLECT
};

class Enemy : public Character
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void Control();
	virtual void Draw();

private:

};

#endif // !ENEMY_H