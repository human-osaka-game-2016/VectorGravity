/**
 * @file	ObjectManager.cpp
 * @breif	すべてのオブジェクトを管理するクラス実装	
 * @author	shibata
 */

#include "ObjectManager.h"
#include "../Character/CharacterManager.h"
#include "../Ui/UiManager.h"



ObjectManager::ObjectManager() :
m_pCharacterManager(new CharacterManager),
m_pUiManager(new UiManager)
{
}

ObjectManager::~ObjectManager()
{
	delete m_pCharacterManager;
	delete m_pUiManager;
}

void ObjectManager::Control()
{
	m_pCharacterManager->Control();

}

void ObjectManager::Draw()
{
	m_pCharacterManager->Draw();
	m_pUiManager->Draw();

}