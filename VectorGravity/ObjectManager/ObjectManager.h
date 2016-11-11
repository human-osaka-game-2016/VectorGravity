/**
 * @file ObjectManager.h
 * @breif �S�ẴI�u�W�F�N�g���Ǘ�����N���X�̃w�b�_�[
 * @author shibata
 */

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

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

};

#endif // !OBJECTMANAGER_H
