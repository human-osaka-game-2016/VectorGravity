/**
 * @file CharcterManager.h
 * @breif キャラクターを管理するクラスのヘッダー
 * @author shibata
 */

#ifndef CHARCTERMANAGER_H
#define CHARCTERMANAGER_H

class Player;
class Tank;

class CharcterManager
{
public:

	CharcterManager();
	~CharcterManager();

	void Control();
	void Draw();

private:

	Player*		m_pPlayer;
	Tank* m_pTank;

};


#endif // !CHARCTERMANAGER_H
