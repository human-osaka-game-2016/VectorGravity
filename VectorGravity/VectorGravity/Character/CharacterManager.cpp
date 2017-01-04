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
	D3DXVECTOR2 m_playerInitPos = DataManager::GetInstance().GetPlayerInitPos();
	std::vector<D3DXVECTOR2>* m_enemyInitPos = DataManager::GetInstance().GetEnemyInitPos();

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
	for (auto i : m_pCharacter)
	{
		delete i;
	}

}

void CharacterManager::Control()
{
	for (auto i : m_pCharacter)
	{
		i->Control();
	}
}

void CharacterManager::Draw()
{
	for (auto i : m_pCharacter)
	{
		i->Draw();
	}
}