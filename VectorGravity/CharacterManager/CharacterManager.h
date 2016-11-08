/**
 * @file CharcterManager.h
 * @breif �L�����N�^�[���Ǘ�����N���X�̃w�b�_�[
 * @author shibata
 */

#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

class Character;

class CharacterManager
{
public:

	CharacterManager();
	~CharacterManager();

	void Control();
	void Draw();

private:

	Character* m_pCharcter;

};


#endif // !CHARACTERMANAGER_H
