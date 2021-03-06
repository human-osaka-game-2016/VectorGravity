/**
 * @file	ObjectManager.cpp
 * @breif	すべてのオブジェクトを管理するクラス実装	
 * @author	shibata
 */

#include "ObjectManager.h"
#include "../Collider/CollisionManager.h"
#include "../Stage/StageManager.h"
#include "../Character/CharacterManager.h"
#include "../BasePoint/BasePoint.h"
#include "../Ui/UiManager.h"
#include "../DataManager/DataManager.h"


ObjectManager::ObjectManager()
{
	CollisionManager::Create();
	m_pStageManager = new StageManager;
	m_pCharacterManager = new CharacterManager;
	m_pBasePoint = new BasePoint;
	m_pUiManager = new UiManager;

}

ObjectManager::~ObjectManager()
{
	delete m_pUiManager;
	delete m_pBasePoint;
	delete m_pCharacterManager;
	delete m_pStageManager;
	CollisionManager::Delete();
}

void ObjectManager::Control()
{
	CollisionManager::GetInstance()->Control();
	m_pStageManager->Control();
	m_pCharacterManager->Control();
	m_pBasePoint->Control();
}

void ObjectManager::Draw()
{
	m_pStageManager->Draw();
	m_pCharacterManager->Draw();
	m_pUiManager->Draw();
}