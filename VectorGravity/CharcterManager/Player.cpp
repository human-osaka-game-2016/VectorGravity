/**
 * @file Player.cpp
 * @breif �L�����N�^�[�̎q�N���X�̎���

 * �v���C���[�N���X�̎���

 * @author shibata
 */

#include "Player.h"

Player::Player() : m_pGD(&GraphicsDevice::GetInstance())
{
	m_texture.LoadTexture("Resource/Texture/player_��.png");
}

Player::~Player()
{

}

void Player::Control()
{

}

void Player::Draw()
{

}

void Player::Attack()
{

}

void Player::Move()
{

}