/**
 * @file	EnemyBulletManager.h
 * @breif	“G‚Ì’e‚ğŠÇ—‚·‚éƒNƒ‰ƒXƒwƒbƒ_
 * @author	shibata
 */

#ifndef ENEMYBULLETMANAGER_H
#define ENEMYBULLETMANAGER_H

#include "BulletManager.h"

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

};

#endif // !ENEMYBULLETMANAGER_H