/**
 * @file	ObjectManager.cpp
 * @breif	���ׂẴI�u�W�F�N�g���Ǘ�����N���X����	
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