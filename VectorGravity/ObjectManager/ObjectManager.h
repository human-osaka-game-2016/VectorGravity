/**
 * @file ObjectManager.h
 * @breif �S�ẴI�u�W�F�N�g���Ǘ�����N���X�̃w�b�_�[
 * @author shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <DirectDrawTexture.h>

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

	CharcterManager*	m_pCharcterManager;
	StageManager*		m_pStageManager;
	UiManager*			m_pUiManager;

	Texture m_texture;
};

#endif // !OBJECTMANAGER_H
