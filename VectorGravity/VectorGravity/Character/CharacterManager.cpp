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

CharacterManager::CharacterManager() :
m_pPlayer(NULL),
m_pLongSoldier(NULL)
{
	D3DXVECTOR2 m_playerInitPos = DataManager::GetInstance()->GetPlayerInitPos();
	std::vector<D3DXVECTOR2>* m_enemyInitPos = DataManager::GetInstance()->GetEnemyInitPos();

	m_pCharacter.push_back(new Player(m_playerInitPos));
	m_pCharacter.push_back(new LongSoldier((*m_enemyInitPos)[0]));
	m_pCharacter.push_back(new LongSoldier((*m_enemyInitPos)[1]));
	m_pCharacter.push_back(new LongSoldier((*m_enemyInitPos)[2]));
	m_pCharacter.push_back(new LongSoldier((*m_enemyInitPos)[3]));
	m_pCharacter.push_back(new LongSoldier((*m_enemyInitPos)[4]));
	m_pCharacter.push_back(new LongSoldier((*m_enemyInitPos)[5]));

}

CharacterManager::~CharacterManager()
{
	DataManager::GetInstance()->ClearEnemyInitPos();

	for (int i = 0; i < m_pCharacter.size(); i++)
	{
		delete m_pCharacter[i];
	}
}

void CharacterManager::Control()
{
	for (int i = 0; i < m_pCharacter.size(); i++)
	{
		m_pCharacter[i]->Control();
		if (m_pCharacter[i]->GetIsDead() == true)
		{
			delete m_pCharacter[i];
			m_pCharacter.erase(m_pCharacter.begin() + i);
		}
	}

}

void CharacterManager::Draw()
{
	for (int i = 0; i < m_pCharacter.size(); i++)
	{
		m_pCharacter[i]->Draw();
	}
}