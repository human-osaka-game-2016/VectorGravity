#include "CharcterManager.h"
#include "Player.h"

CharcterManager::CharcterManager() : 
m_pPlayer(new Player)
{

}

CharcterManager::~CharcterManager()
{

}

void CharcterManager::Control()
{
	Character* charaControlList[2] = 
	{
		m_pPlayer
	};
}

void CharcterManager::Draw()
{
	Character* charaDrawList[2] =
	{
		m_pPlayer
	};
}