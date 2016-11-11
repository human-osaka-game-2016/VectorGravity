/**
 * @file NormalBullet.h
 * @breif �ʏ�e�̃N���X�w�b�_�\
 * @author shibata
 */

#ifndef NORMALBULLET_H
#define NORMALBULLET_H

#include "Bullet.h"
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
};

#endif // !NORMALBULLET_H
