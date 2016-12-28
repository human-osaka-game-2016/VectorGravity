/**
 * @file	Player.h
 * @breif	プレイヤーのクラスヘッダ
 * @author	shibata
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "../Collider/Collider.h"
#include "../MyRect.h"

class InputKey;
class Sound;
class Collider;
class StateManager;

#define MOVE_SPEED 12
#define PLAYER_SIZE 128
#define JUMPPOWER 20
#define GRAVITY 0.01

enum VectorDirection
{
	VECTOR_UP,
	VECTOR_DOWN,
	VECTOR_LEFT,
	VECTOR_RIGHT
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

	Player(D3DXVECTOR2);
	virtual ~Player();

	virtual void Control();
	virtual void Draw();
	void Move();

private:

	VectorDirection VectorOrient();

	VectorDirection	m_vectorDirection;
	PlayerState		m_playerState;
	Angle			m_angle;
	BulletKind		m_bulletKind;
	InputKey*		m_pInputKey;
	Sound*			m_pSound;

	MyRect m_playerRect;

	bool m_topFieldHits;
	bool m_bottomFieldHits;
	bool m_rightFieldHits;
	bool m_leftFieldHits;
	bool m_bottomFieldHits2;

	float m_moveSpeedX;
	float m_moveSpeedY;

	float m_jumpPower;
	float m_gravity;
	float m_freeGravity;

	float m_gravityPower;

	bool m_isJump;
	bool m_upFlag;
	bool m_downFlag;

	MyRect m_baseRect;
	D3DXVECTOR2 distance;

	std::vector<Collider::ColliderID> m_colliderIDs;

	Collider* m_pCollider;

	MyRect m_basePointRect;

	StateManager* m_pStateManager;

	//初期位置を受け取るメンバ変数
	D3DXVECTOR2 m_initPos;

	int				m_Hp;
	int				m_Gp;

};

#endif // !PLAYER_H