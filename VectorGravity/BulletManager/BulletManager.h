/**
 * @file BulletManager.h
 * @breif 弾の生成の管理をしているクラスのヘッダー
 * @author shibata
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

	void Control();
	void Draw();
	void Create();

private:

	NormalBullet* m_pNormalBullet;
	StateManager* m_pStateManager;
	VectorDirection m_vectorDirection;
};

#endif // !BULLETMANAGER_H
