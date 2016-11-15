#include "CharacterManager.h"
#include "Player.h"
#include"Tank.h"

CharacterManager::CharacterManager() : 
m_pPlayer(new Player)
{
	m_pTank = new Tank;
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
		m_pPlayer, m_pTank
	};

	for (int i = 0; i < 2; i++)
	{
		charaControlList[i]->Control();
	}
}

void CharacterManager::Draw()
{
	Character* charaDrawList[2] =
	{
		m_pPlayer, m_pTank
	};

	for (int i = 0; i < 2; i++)
	{
		charaDrawList[i]->Draw();
	}
}