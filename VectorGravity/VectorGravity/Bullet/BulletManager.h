/**
 * @file	BulletManager.h
 * @breif	すべての弾を管理するクラスヘッダ
 * @auhtor	shibata
 */

#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

class NormalBullet;
class StateManager;
enum VectorDirection;

class BulletManager
{
public:

	BulletManager();
	~BulletManager();

	virtual void Control();
	virtual void Draw();
	virtual void CreateBullet();
};

#endif // !BULLETMANAGER_H