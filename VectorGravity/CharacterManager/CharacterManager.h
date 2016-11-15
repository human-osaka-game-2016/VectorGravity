/**
 * @file CharcterManager.h
 * @breif キャラクターを管理するクラスのヘッダー
 * @author shibata
 */

#ifndef CHARACTERMANAGER_H
#define CHARACTERMANAGER_H

class Player;
class Tank;

class CharacterManager
{
public:

	CharacterManager();
	~CharacterManager();

	void Control();
	void Draw();

private:

	Player*		m_pPlayer;
	Tank* m_pTank;

};


#endif // !CHARACTERMANAGER_H
