/**
 * @file NormalBullet.h
 * @breif 通常弾のクラスヘッダ―
 * @author shibata
 */

#ifndef NORMALBULLET_H
#define NORMALBULLET_H

#include "Bullet.h"
#include "../CollisionManager/Collision.h"
#include <DirectInput.h>

class NormalBullet : public Bullet
{
public:

	NormalBullet();
	~NormalBullet();

	virtual void Control();
	virtual void Draw();
	virtual void Attack();

private:

	InputKeyBorad* m_pInputKey;
	RECT m_normalBulletRect;
	bool m_hits;
};

#endif // !NORMALBULLET_H
