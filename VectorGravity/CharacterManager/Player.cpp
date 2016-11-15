/**
 * @file Player.cpp
 * @breif キャラクターの子クラスの実装

 * プレイヤークラスの実装

 * @author shibata
 */

#include "Player.h"
#include"../BulletManager/BulletManager.h"
#include "../StateManager/StateManager.h"

Player::Player() : 
m_pInputKey(&InputKeyBorad::GetInstance()),
m_bulletManager(new BulletManager),
m_pStateManager(&StateManager::GetInstance())
{
	m_texture.LoadTexture("Resource/Texture/player_β.png");
	m_playerRect = { 0, 572, 128, 682};		// どうにかしてほかの描画方法を探す
}

Player::~Player()
{
	delete m_bulletManager;
}

void Player::Control()
{
	m_pInputKey->KeyCheck(DIK_A, A);
	m_pInputKey->KeyCheck(DIK_D, D);
	m_pInputKey->KeyCheck(DIK_SPACE, SPACE);
	m_pInputKey->KeyCheck(DIK_UP, UP);
	m_pInputKey->KeyCheck(DIK_DOWN, DOWN);
	m_pInputKey->KeyCheck(DIK_LEFT, LEFT);
	m_pInputKey->KeyCheck(DIK_RIGHT, RIGHT);

	m_bulletManager->Control();
	Move();
	m_vectorDirection = VectorOrient();
	m_pStateManager->SetVectorDirection(m_vectorDirection);
	Attack();

}

void Player::Draw()
{
	CUSTOMVERTEX player[4]
	{
		{ m_playerRect.left, m_playerRect.top,  1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f},
		{ m_playerRect.right, m_playerRect.top, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ m_playerRect.right, m_playerRect.bottom, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ m_playerRect.left, m_playerRect.bottom, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};
	m_bulletManager->Draw();

	m_texture.SetTexture(player);
}

void Player::Attack()
{
	if (m_pInputKey->m_Key[SPACE] == ON)
	{
		m_bulletManager->Create();
	}
}

void Player::Move()
{
	if (m_pInputKey->m_Key[A] == ON)
	{
		m_playerRect.right -= MOVE_SPEED;
		m_playerRect.left -= MOVE_SPEED;
	}
	if (m_pInputKey->m_Key[D] == ON)
	{
		m_playerRect.right += MOVE_SPEED;
		m_playerRect.left += MOVE_SPEED;
	}


}

VectorDirection Player::VectorOrient()
{
	if (m_pInputKey->m_Key[UP] == ON)
	{
		m_vectorDirection = Vector_Up;
	}

	if (m_pInputKey->m_Key[DOWN] == ON)
	{
		m_vectorDirection = Vector_Down;
	}

	if (m_pInputKey->m_Key[LEFT] == ON)
	{
		m_vectorDirection = Vector_Left;
	}

	if (m_pInputKey->m_Key[RIGHT] == ON)
	{
		m_vectorDirection = Vector_Right;
	}

	return m_vectorDirection;
}