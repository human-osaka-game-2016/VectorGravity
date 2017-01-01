/**
 * @file	CharacterManager.cpp
 * @breif	キャラクターを管理するクラス実装
 * @author	shibata
 */

#include "CharacterManager.h"
#include "../DataManager/DataManager.h"
#include "Character.h"
#include "Tank.h"
#include "LongSoldier.h"
#include "Player.h"

CharacterManager::CharacterManager()
{
	std::vector<D3DXVECTOR2>* m_enemyInitPos = DataManager::GetInstance().GetEnemyInitPos();
	D3DXVECTOR2 m_playerInitPos = DataManager::GetInstance().GetPlayerInitPos();

	m_pPlayer = new Player(m_playerInitPos);
	m_pLongSoldier = new LongSoldier((*m_enemyInitPos)[0]);
}

CharacterManager::~CharacterManager()
{
	delete m_pPlayer;
	delete m_pLongSoldier;
}

void CharacterManager::Control()
{
	Character* charaControlList[2] =
	{
		m_pPlayer, m_pLongSoldier
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
		 m_pPlayer, m_pLongSoldier
	};

	for (int i = 0; i < 2; i++)
	{
		characterDrawList[i]->Draw();
	}
}