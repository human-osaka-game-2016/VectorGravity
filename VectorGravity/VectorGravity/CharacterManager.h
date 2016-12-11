/**
* @file		CharcterManager.h
* @breif	�L�����N�^�[���Ǘ�����N���X�̃w�b�_
* @author	shibata
*/

#ifndef CHARCTERMANAGER_H
#define CHARCTERMANAGER_H

#include <vector>

class Character;

class CharacterManager
{
public:

	CharacterManager();
	~CharacterManager();

	void Control();
	void Draw();

private:

	std::vector<Character*>		m_pCharacter;

};
#endif // !CHARCTERMANAGER_H
