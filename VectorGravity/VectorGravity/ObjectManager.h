/**
* @file ObjectManager.h
* @breif �S�ẴI�u�W�F�N�g���Ǘ�����N���X�̃w�b�_�[
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
