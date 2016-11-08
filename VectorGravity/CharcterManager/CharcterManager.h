/**
 * @file CharcterManager.h
 * @breif キャラクターを管理するクラスのヘッダー
 * @author shibata
 */

#ifndef CHARCTERMANAGER_H
#define CHARCTERMANAGER_H

class Character;
class Player;

class CharcterManager
{
public:

	CharcterManager();
	~CharcterManager();

	void Control();
	void Draw();

private:

	Character*	m_pCharacter;
	Player*		m_pPlayer;


};


#endif // !CHARCTERMANAGER_H
