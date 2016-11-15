/**
 * @file Player.h
 * @breif 主人公のクラスヘッダー
 * @author shibata
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <DirectInput.h>

class BulletManager;
class StateManager;

enum VectorDirection
{
	Vector_Up,
	Vector_Down,
	Vector_Left,
	Vector_Right,
	Vector_Up_Left,
	Vector_Up_Right,
	Vector_Down_Left,
	Vector_Down_Right,

};

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
	BulletManager* m_bulletManager;
	RECT m_playerRect;
	VectorDirection m_vectorDirection;
	StateManager* m_pStateManager;

private:

	VectorDirection VectorOrient();

};


#endif // !PLAYER_H
