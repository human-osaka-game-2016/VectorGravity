/**
 * @file	ObjectManager.cpp
 * @breif	すべてのオブジェクトを管理するクラス実装	
 * @author	shibata
 */

#include "ObjectManager.h"
#include "../Stage/StageManager.h"
#include "../Character/CharacterManager.h"
#include "../BasePoint/BasePoint.h"
#include "../Ui/UiManager.h"


ObjectManager::ObjectManager() :
m_pCharacterManager(new CharacterManager),
m_pStageManager(new StageManager),
m_pBasePoint(new BasePoint),
m_pUiManager(new UiManager)
{
}

ObjectManager::~ObjectManager()
{
	delete m_pCharacterManager;
	delete m_pStageManager;
	delete m_pBasePoint;
	delete m_pUiManager;
}

void ObjectManager::Control()
{
	m_pCharacterManager->Control();
	m_pStageManager->Control();
	m_pBasePoint->Control();
}

void ObjectManager::Draw()
{
	m_pCharacterManager->Draw();
	m_pStageManager->Draw();
	m_pUiManager->Draw();
}