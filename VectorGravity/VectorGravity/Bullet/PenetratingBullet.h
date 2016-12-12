/**
 * @file	PenetratingBullet.h
 * @breif	貫通弾のクラスヘッダ
 * @auhtor	shibata
 */

#ifndef PENETRATINGBULLET_H
#define PENETRATINGBULLET_H

#include "Bullet.h"

class PenetratingBullet : public Bullet
{
public:

	PenetratingBullet();
	~PenetratingBullet();

	virtual void Control();
	virtual void Draw();

};

#endif // !PENETRATINGBULLET_H