/**
 * @file	CharacterManager.cpp
 * @breif	キャラクターを管理するクラス実装
 * @author	shibata
 */

#include "CharacterManager.h"
#include "Character.h"
#include "Tank.h"
#include "Player.h"

CharacterManager::CharacterManager() :
m_pTank(new Tank),
m_pPlayer(new Player)
{
}

CharacterManager::~CharacterManager()
{
	delete m_pPlayer;
	delete m_pTank;
}

void CharacterManager::Control()
{
	Character* charaControlList[2] =
	{
		m_pTank, m_pPlayer
	};

	for (int i = 0; i < 2; i++)
	{
		charaControlList[i]->Control();
	}
}

void CharacterManager::Draw()
{
	Character* characterDrawList[2] = 
	{
		m_pTank, m_pPlayer
	};

	for (int i = 0; i < 2; i++)
	{
		characterDrawList[i]->Draw();
	}
}