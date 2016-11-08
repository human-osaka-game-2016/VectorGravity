#include "ObjectManager.h"
#include "../BulletManager/BulletManager.h"
#include "../CharcterManager/CharcterManager.h"
#include "../StageManager/StageManager.h"
#include "../UiManager/UiManager.h"

ObjectManager::ObjectManager() : 
m_pBulletManager(new BulletManager),
m_pCharcterManager(new CharcterManager),
m_pStageManager(new StageManager),
m_pUiManager(new UiManager)
{

}

ObjectManager::~ObjectManager()
{
	delete m_pBulletManager;
	delete m_pCharcterManager;
	delete m_pStageManager;
	delete m_pUiManager;
}

void ObjectManager::Control()
{
	m_pBulletManager->Control();
	m_pCharcterManager->Control();
	m_pStageManager->Control();
	m_pUiManager->Control();

}

void ObjectManager::Draw()
{
	m_pBulletManager->Draw();
	m_pCharcterManager->Draw();
	m_pStageManager->Draw();
	m_pUiManager->Draw();

}