/**
 * @file	NormalBullet.h
 * @breif	通常弾のクラスヘッダ
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
	void Charge();	///@todo　Bulletにこの関数が必要なのか疑問なので後に要検討

	virtual void Attack();

	MyRect GetRect()
	{
		return m_normalBulletRect;
	}

private:
	Collider* m_pCollider;
	InputKey*		m_pInputKey;
	bool  m_hits;
	bool  m_fieldHits;
	float m_posX;
	float m_posY;

	D3DXVECTOR2 m_playerPos;

	PlayerDirection m_playerDirection;
	MyRect m_normalBulletRect;
	MyRect m_baseRect;

	D3DXVECTOR2   m_base;

	D3DXVECTOR2 distance;

	std::vector<Collider::ColliderID> m_colliderIDs;

};

#endif // !NORMALBULLET_H