/**
 * @file Player.h
 * @breif 主人公のクラスヘッダー
 * @author shibata
 */
/**
 * @file Player.h
 * @breif キャラクターの子クラスヘッダー
 * @author shibata
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

/// 主人公のクラス
class Player : public Character
{
public:

	Player();
	virtual ~Player();

	virtual void Control();
	virtual void Draw();
	virtual void Attack();
	virtual void Move();

private:

	InputKeyBorad* m_pInputKey;
	RECT m_playerRect;

};


#endif // !PLAYER_H
