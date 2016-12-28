/**
 * @file	CharacterManager.cpp
 * @breif	キャラクターを管理するクラス実装
 * @author	shibata
 */

#include "CharacterManager.h"
#include "../DataManager/DataManager.h"
#include "Character.h"
#include "Tank.h"
#include "Player.h"

CharacterManager::CharacterManager()
{
	D3DXVECTOR2 m_playerInitPos = DataManager::GetInstance().GetPlayerInitPos();

	m_pPlayer = new Player(m_playerInitPos);
}

CharacterManager::~CharacterManager()
{
	delete m_pPlayer;
}

void CharacterManager::Control()
{
	Character* charaControlList[1] =
	{
		m_pPlayer
	};

	for (int i = 0; i < 1; i++)
	{
		charaControlList[i]->Control();
	}
}

void CharacterManager::Draw()
{
	Character* characterDrawList[1] = 
	{
		 m_pPlayer
	};

	for (int i = 0; i < 1; i++)
	{
		characterDrawList[i]->Draw();
	}
}