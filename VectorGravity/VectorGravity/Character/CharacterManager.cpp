/**
 * @file	CharacterManager.cpp
 * @breif	キャラクターを管理するクラス実装
 * @author	shibata
 */

#include "CharacterManager.h"
#include "Character.h"

CharacterManager::CharacterManager()
{
}

CharacterManager::~CharacterManager()
{
	for (unsigned int charaNumber = 0; charaNumber < m_pCharacter.size(); charaNumber++)
	{
		delete m_pCharacter[charaNumber];
	}
}

void CharacterManager::Control()
{
	for (unsigned int charaNumber = 0; charaNumber < m_pCharacter.size(); charaNumber++)
	{
		m_pCharacter[charaNumber]->Control();
	}
}

void CharacterManager::Draw()
{
	for (unsigned int charaNumber = 0; charaNumber < m_pCharacter.size(); charaNumber++)
	{
		m_pCharacter[charaNumber]->Draw();
	}
}