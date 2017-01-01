/**
 * @file	PlayerBulletManager.h
 * @breif	プレイヤーの弾を管理するクラスヘッダ
 * @author	shibata
 */

#ifndef PLAYERBULLETMANAGER_H
#define PLAYERBULLETMANAGER_H

#include "BulletManager.h"
#include <vector>

class Collider;

class PlayerBulletManager : public BulletManager
{
public:

	PlayerBulletManager();
	~PlayerBulletManager();

	virtual void Control();
	virtual void Draw();
	virtual void CreateBullet();

private:
	static const int m_BulletMax;

	std::vector<NormalBullet*> m_pNormalBullets;

	int m_BulletNum;

	Collider* m_pCollider[4];

};

#endif // !PLAYERBULLETMANAGER_H