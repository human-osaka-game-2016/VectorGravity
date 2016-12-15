/**
 * @file	CharacterManager.cpp
 * @breif	キャラクターを管理するクラス実装
 * @author	shibata
 */

#include "CharacterManager.h"
#include "Character.h"
#include "Tank.h"

CharacterManager::CharacterManager() :
m_pTank(new Tank)
{
}

CharacterManager::~CharacterManager()
{
	delete m_pTank;
}

void CharacterManager::Control()
{
	Character* charaControlList[1] =
	{
		m_pTank
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
		m_pTank
	};

	for (int i = 0; i < 1; i++)
	{
		characterDrawList[i]->Draw();
	}
}