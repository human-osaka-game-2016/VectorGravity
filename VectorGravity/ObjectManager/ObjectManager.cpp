#include "ObjectManager.h"
#include "../BulletManager/BulletManager.h"
#include "../CharacterManager/CharacterManager.h"
#include "../StageManager/StageManager.h"
#include "../UiManager/UiManager.h"



ObjectManager::ObjectManager() : 
m_pCharacterManager(new CharacterManager),
m_pStageManager(new StageManager),
m_pUiManager(new UiManager)
{
	m_texture.LoadTexture("Resource/Texture/BackGround.png");
}

ObjectManager::~ObjectManager()
{
	delete m_pCharacterManager;
	delete m_pStageManager;
	delete m_pUiManager;
}

void ObjectManager::Control()
{
	m_pCharacterManager->Control();
	m_pStageManager->Control();
	m_pUiManager->Control();

}

void ObjectManager::Draw()
{
	CUSTOMVERTEX BackGround[4]
	{
		{    0.0f,   0.0f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f},
		{ 1280.0f,   0.0f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ 1280.0f, 720.0f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{    0.0f, 720.0f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	m_texture.SetTexture(BackGround);

	m_pCharacterManager->Draw();
	m_pStageManager->Draw();
	m_pUiManager->Draw();

}