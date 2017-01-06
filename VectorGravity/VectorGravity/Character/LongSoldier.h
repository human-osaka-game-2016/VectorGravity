#ifndef LONGSOLDIER_H
#define LONGSOLDIER_H

#include "Enemy.h"
#include "../MyRect.h"

#define LONGSOLDIER_SIZE 128
#define BLOWSPEED 20

class Collider;
class StateManager;
class EnemyBulletManager;
class InputKey;
class InputContlloer;
class SoundManager;

class LongSoldier : public Enemy
{
public:
	LongSoldier(D3DXVECTOR2);
	~LongSoldier();

	virtual void Control();
	virtual void Draw();
	void Attack();
	void Search();

private:

	MyRect m_longSoldierRect;
	MyRect m_baseRect;

	D3DXVECTOR2   m_base;
	Collider*     m_pCollider;
	StateManager* m_pStateManager;
	InputKey*     m_pInputKey;
	InputContlloer*	m_pInputContlloer;
	EnemyBulletManager* m_pEnemyBulletManager;
	SoundManager*	m_pSoundManager;

	std::vector<Collider::ColliderID> m_colliderIDs;

	int m_XBlow;
	int m_YBlow;

	bool m_hits;
	bool m_soldierhits;
	bool m_rightFieldHits;
	bool m_leftFieldHits;
	bool m_topFieldHits;
	bool m_bottomFieldHits;

	float m_playerPosX;
	float m_playerPosY;
	float m_searchRange;
	float m_playerDistance;


};

#endif // !LONGSOLDIER_H