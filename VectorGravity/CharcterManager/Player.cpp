/**
 * @file Player.cpp
 * @breif �L�����N�^�[�̎q�N���X�̎���

 * �v���C���[�N���X�̎���

 * @author shibata
 */

#include "Player.h"

Player::Player() : m_pInputKey(&InputKeyBorad::GetInstance())
{
	m_texture.LoadTexture("Resource/Texture/player_��.png");
	m_playerRect = { 0, 572, 128, 682};		// �ǂ��ɂ����Ăق��̕`����@��T��
}

Player::~Player()
{

}

void Player::Control()
{
	m_pInputKey->KeyCheck(DIK_A, A);
	m_pInputKey->KeyCheck(DIK_D, D);

	Move();

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

	m_texture.SetTexture(player);
}

void Player::Attack()
{

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