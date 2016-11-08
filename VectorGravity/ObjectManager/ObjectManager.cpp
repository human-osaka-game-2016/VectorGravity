#include "ObjectManager.h"
#include "../BulletManager/BulletManager.h"
#include "../CharacterManager/CharacterManager.h"
#include "../StageManager/StageManager.h"
#include "../UiManager/UiManager.h"

ObjectManager::ObjectManager() : 
m_pBulletManager(new BulletManager),
m_pCharacterManager(new CharacterManager),
m_pStageManager(new StageManager),
m_pUiManager(new UiManager)
{

}

ObjectManager::~ObjectManager()
{
	delete m_pBulletManager;
	delete m_pCharacterManager;
	delete m_pStageManager;
	delete m_pUiManager;
}

void ObjectManager::Control()
{
	m_pBulletManager->Control();
	m_pCharacterManager->Control();
	m_pStageManager->Control();
	m_pUiManager->Control();

}

void ObjectManager::Draw()
{
	m_pBulletManager->Draw();
	m_pCharacterManager->Draw();
	m_pStageManager->Draw();
	m_pUiManager->Draw();

}