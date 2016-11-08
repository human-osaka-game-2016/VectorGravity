#include "CharcterManager.h"
#include "Player.h"

CharcterManager::CharcterManager() : 
m_pPlayer(new Player)
{

}

CharcterManager::~CharcterManager()
{
	delete m_pPlayer;
}

void CharcterManager::Control()
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

void CharcterManager::Draw()
{
	Character* charaDrawList[1] =
	{
		m_pPlayer
	};

	for (int i = 0; i < 1; i++)
	{
		charaDrawList[i]->Draw();
	}
}