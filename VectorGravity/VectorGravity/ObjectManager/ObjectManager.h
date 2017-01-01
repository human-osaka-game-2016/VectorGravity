/**
* @file		ObjectManager.h
* @breif	全てのオブジェクトを管理するクラスヘッダ
* @author	shibata
*/

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class StageManager;
class CharacterManager;
class BasePoint;
class UiManager;

class ObjectManager
{
public:

	ObjectManager();
	~ObjectManager();

	void Control();
	void Draw();

private:

	StageManager*		m_pStageManager;
	CharacterManager*	m_pCharacterManager;
	BasePoint*			m_pBasePoint;
	UiManager*			m_pUiManager;

};

#endif // !OBJECTMANAGER_H