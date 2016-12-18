/**
 * @file	Player.cpp
 * @breif	プレイヤーのクラス実装
 * @author	shibata
 */

#include "Player.h"
#include <Texture.h>
#include <Vertex.h>
#include <InputKey.h>
#include <Sound.h>

Player::Player() : 
m_pInputKey(&InputKey::Instance()),
m_pSound(&Sound::Instance())
{
}

Player::~Player()
{
	delete m_pTexture;
	delete m_pVertex;
}

void Player::Control()
{
	m_pInputKey->CheckKey(DIK_SPACE, SPACE);

	if (m_pInputKey->m_key[SPACE] == PUSH)
	{
		m_pSound->LoadSoundFile("Resource/Sound/sen_ka_yumi01.wav");
		m_pSound->SoundState(PLAY);
	}
}

void Player::Draw()
{

}