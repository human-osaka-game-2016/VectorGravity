/**
 * @file	Player.cpp
 * @breif	�v���C���[�̃N���X����
 * @author	shibata
 */

#include "Player.h"
#include <Texture.h>
#include <Vertex.h>

Player::Player()
{
	m_pTexture = new Texture;
	m_pVertex = new Vertex;
}

Player::~Player()
{
	delete m_pTexture;
	delete m_pVertex;
}

void Player::Control()
{

}

void Player::Draw()
{

}