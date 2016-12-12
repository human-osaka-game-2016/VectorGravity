/**
 * @file	PlayerBulletManager.h
 * @breif	�v���C���[�̒e���Ǘ�����N���X�w�b�_
 * @author	shibata
 */

#ifndef PLAYERBULLETMANAGER_H
#define PLAYERBULLETMANAGER_H

#include "BulletManager.h"

class PlayerBulletManager : public BulletManager
{
public:

	PlayerBulletManager();
	~PlayerBulletManager();

	virtual void Control();
	virtual void Draw();
	virtual void CreateBullet();
};

#endif // !PLAYERBULLETMANAGER_H