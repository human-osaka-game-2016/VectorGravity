/**
* @file		CharacterManager.h
* @breif	キャラクターを管理するクラスのヘッダ
* @author	shibata
*/

#ifndef CHARCTERMANAGER_H
#define CHARCTERMANAGER_H

#include <vector>

class Character;
class Tank;

class CharacterManager
{
public:

	CharacterManager();
	~CharacterManager();

	void Control();
	void Draw();

private:

	std::vector<Character*>		m_pCharacter;
	Tank* m_pTank;

};

#endif // !CHARCTERMANAGER_H