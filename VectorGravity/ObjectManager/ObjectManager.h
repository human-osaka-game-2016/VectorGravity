/**
 * @file ObjectManager.h
 * @breif 全てのオブジェクトを管理するクラスのヘッダー
 * @author shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class BulletManager;
class CharcterManager;
class StageManager;
class UiManager;

class ObjectManager
{
public:

	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

private:

	BulletManager*		m_pBulletManager;
	CharcterManager*	m_pCharcterManager;
	StageManager*		m_pStageManager;
	UiManager*			m_pUiManager;

};

#endif // !OBJECTMANAGER_H
