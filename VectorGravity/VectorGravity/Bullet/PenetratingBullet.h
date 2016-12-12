/**
 * @file	PenetratingBullet.h
 * @breif	�ђʒe�̃N���X�w�b�_
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