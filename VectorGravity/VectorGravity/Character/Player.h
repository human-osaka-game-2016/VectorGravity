/**
 * @file	Player.h
 * @breif	プレイヤーのクラスヘッダ
 * @author	shibata
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

#define MOVE_SPEED 12
#define PLAYER_SIZE 128

enum VectorDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

enum BulletKind
{
	NORMAL,
	GUM,
	PENETRATING
};

enum Angle
{

};

enum PlayerState
{
	STEY,
	MOVE,
	JUMP,
};

class Player : public Character
{
public:

	Player();
	virtual ~Player();

	virtual void Control();
	virtual void Draw();

private:

	VectorDirection	m_vectorDirection;
	PlayerState		m_playerState;
	Angle			m_angle;
	BulletKind		m_bulletKind;

	int				m_Hp;
	int				m_Gp;

};

#endif // !PLAYER_H