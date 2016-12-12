/**
 * @file	GumBullet.h
 * @breif	ƒSƒ€’e‚ÌƒNƒ‰ƒXƒwƒbƒ_
 * @author	shibata
 */

#ifndef GUMBULLET_H
#define GUMBULLET_H

#include "Bullet.h"

class GumBullet : public Bullet
{
public:

	GumBullet();
	~GumBullet();

	virtual void Control();
	virtual void Draw();
	void Bound();

};

#endif // !GUMBULLET_H