/**
* @file ObjectManager.h
* @breif 全てのオブジェクトを管理するクラスのヘッダー
* @author shibata
*/

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H


class CharacterManager;
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
	UiManager*			m_pUiManager;

};

#endif // !OBJECTMANAGER_H
