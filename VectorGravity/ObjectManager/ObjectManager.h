/**
 * @file ObjectManager.h
 * @breif 全てのオブジェクトを管理するクラスのヘッダー
 * @author shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class BulletManager;
class CharacterManager;
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
	CharacterManager*	m_pCharacterManager;
	StageManager*		m_pStageManager;
	UiManager*			m_pUiManager;

};

#endif // !OBJECTMANAGER_H
