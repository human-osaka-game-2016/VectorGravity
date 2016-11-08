/**
 * @file Player.cpp
 * @breif キャラクターの子クラスの実装

 * プレイヤークラスの実装

 * @author shibata
 */

#include "Player.h"

Player::Player() : m_pGD(&GraphicsDevice::GetInstance())
{
	m_texture.LoadTexture("Resource/Texture/player_β.png");
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