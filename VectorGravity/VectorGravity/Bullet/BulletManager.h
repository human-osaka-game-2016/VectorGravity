/**
 * @file	BulletManager.h
 * @breif	���ׂĂ̒e���Ǘ�����N���X�w�b�_
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