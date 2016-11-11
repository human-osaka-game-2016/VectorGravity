#include "CharcterManager.h"
#include "Player.h"
#include"Tank.h"

CharcterManager::CharcterManager() : 
m_pPlayer(new Player)
{
	m_pTank = new Tank;
}

CharcterManager::~CharcterManager()
{
	delete m_pPlayer;
	delete m_pTank;
}

void CharcterManager::Control()
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

void CharcterManager::Draw()
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