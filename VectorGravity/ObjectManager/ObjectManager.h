/**
 * @file ObjectManager.h
 * @breif 全てのオブジェクトを管理するクラスのヘッダー
 * @author shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <DirectDrawTexture.h>

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

	CharacterManager*	m_pCharacterManager;
	StageManager*		m_pStageManager;
	UiManager*			m_pUiManager;

	Texture m_texture;
};

#endif // !OBJECTMANAGER_H
