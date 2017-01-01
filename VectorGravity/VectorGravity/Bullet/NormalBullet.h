/**
 * @file	NormalBullet.h
 * @breif	�ʏ�e�̃N���X�w�b�_
 * @author	shibata
 */

#ifndef NORMALBULLET_H
#define NORMALBULLET_H

#include "Bullet.h"
#include <InputKey.h>
#include "PlayerBulletManager.h"
#include "../MyRect.h"
#include "../Character/Player.h"

class InputKey;

#define NORMALBULLET_SIZE 32
#define NORMALBULLET_SPEED 10

class NormalBullet : public Bullet
{
public:

	NormalBullet(Collider*);
	~NormalBullet();

	virtual void Control();
	virtual void Draw();
	void Bound();
	void Charge();	///@todo�@Bullet�ɂ��̊֐����K�v�Ȃ̂��^��Ȃ̂Ō�ɗv����

	virtual void Attack();

	MyRect GetRect()
	{
		return m_normalBulletRect;
	}

private:
	Collider* m_pCollider;
	InputKey*		m_pInputKey;
	bool  m_hits;
	float m_posX;
	float m_posY;

	D3DXVECTOR2 m_playerPos;

	PlayerDirection m_playerDirection;
	MyRect m_normalBulletRect;

};

#endif // !NORMALBULLET_H