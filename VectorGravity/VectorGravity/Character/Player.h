/**
 * @file	Player.h
 * @breif	プレイヤーのクラスヘッダ
 * @author	shibata
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

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

class Player : public Character
{
public:

	Player();
	~Player();

	virtual void Control();
	virtual void Draw();

};

#endif // !PLAYER_H