/**
 * @file	EnemyBulletManager.h
 * @breif	“G‚Ì’e‚ğŠÇ—‚·‚éƒNƒ‰ƒXƒwƒbƒ_
 * @author	shibata
 */

#ifndef ENEMYBULLETMANAGER_H
#define ENEMYBULLETMANAGER_H

#include "BulletManager.h"
#include <vector>

class Collider;

enum EnemyID
{
	TANK,
	CANNON,
	SOLDIER
};


class EnemyBulletManager : public BulletManager
{
public:

	EnemyBulletManager();
	~EnemyBulletManager();

	virtual void Control();
	virtual void Draw();
	virtual void CreateBullet(EnemyID enmeyID_);

private:
	static const int m_BulletMax;

	std::vector<SoldierBullet*> m_pSoldierBullets;

	int m_BulletNum;

	Collider* m_pCollider[4];

};

#endif // !ENEMYBULLETMANAGER_H