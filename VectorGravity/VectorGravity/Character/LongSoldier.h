#ifndef LONGSOLDIER_H
#define LONGSOLDIER_H

#include "Enemy.h"
#include "../Collider/Collider.h"
#include "../MyRect.h"

#define LONGSOLDIER_SIZE 128

class Collider;

class LongSoldier : public Enemy
{
public:
	LongSoldier(D3DXVECTOR2);
	~LongSoldier();

	virtual void Control();
	virtual void Draw();

private:

	MyRect m_longSoldierRect;
	MyRect m_baseRect;
	D3DXVECTOR2 m_base;
	Collider* m_pCollider;
	std::vector<Collider::ColliderID> m_colliderIDs;

	float m_posX;
	float m_posY;

};

#endif // !LONGSOLDIER_H