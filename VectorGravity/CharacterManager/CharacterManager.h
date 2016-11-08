/**
 * @file CharcterManager.h
 * @breif キャラクターを管理するクラスのヘッダー
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
