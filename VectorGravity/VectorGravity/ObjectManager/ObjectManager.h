/**
* @file		ObjectManager.h
* @breif	全てのオブジェクトを管理するクラスヘッダ
* @author	shibata
*/

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

class CharacterManager;
class StageManager;
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

	CharacterManager*	m_pCharacterManager;
	StageManager*		m_pStageManager;
	BasePoint*			m_pBasePoint;
	UiManager*			m_pUiManager;

};

#endif // !OBJECTMANAGER_H