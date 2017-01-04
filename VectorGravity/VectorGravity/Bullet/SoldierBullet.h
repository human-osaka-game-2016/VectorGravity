#ifndef SOLDIERBULLET_H
#define SOLDIERBULLET_H

#include "Bullet.h"
#include <InputKey.h>
#include "PlayerBulletManager.h"
#include "../MyRect.h"
#include "../Character/Player.h"

class InputKey;

class SoldierBullet : Bullet
{
public:

	SoldierBullet();
	~SoldierBullet();
	virtual void Control();
	virtual void Draw();
	virtual void Attack();

	MyRect GetRect()
	{
		return m_soldierBulletRect;
	}

private:
	Collider* m_pCollider;
	InputKey*		m_pInputKey;
	bool  m_hits;
	bool  m_fieldHits;
	float m_posX;
	float m_posY;

	D3DXVECTOR2 m_enemyPos;

	MyRect m_soldierBulletRect;
	MyRect m_baseRect;

	D3DXVECTOR2   m_base;

	D3DXVECTOR2 distance;

	std::vector<Collider::ColliderID> m_colliderIDs;

};

#endif // !SOLDIERBULLET_H