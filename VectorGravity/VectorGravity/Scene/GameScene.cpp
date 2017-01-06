/**
* @file	GameScene.cpp
* @breif	ゲームシーンのクラス実装
* @author	shibata
*/

#include "GameScene.h"
#include "SceneFactory.h"
#include "../ObjectManager/ObjectManager.h"
#include "../DataManager/DataManager.h"
#include <SoundManager.h>
#include <InputKey.h>

GameScene::GameScene() :
m_pObjectManager(new ObjectManager),
m_pInputKey(&InputKey::Instance()),
m_pauses(false),
m_pSoundManager(new SoundManager),
m_pDataManager(&DataManager::GetInstance())
{
	m_pSoundManager->LoadSoundFile(GAME_BGM, "Resource/Sound/BG_Gamescene.wav");
	m_pSoundManager->SoundState(GAME_BGM, Sound::LOOP);
}

GameScene::~GameScene()
{
	m_pSoundManager->SoundState(GAME_BGM, Sound::STOP);
	delete m_pObjectManager;
	delete m_pSoundManager;

}

SceneID GameScene::Control()
{
	SceneID nextScene = SceneID::GAME_SCENE;

	m_pInputKey->CheckKey(DIK_Q, Q);

	if (!m_pauses)
	{
		m_pObjectManager->Control();
	}
	else
	{
		ControlPause();
	}

	if (m_pDataManager->GetPlayerDead())
	{
		nextScene = GAME_OVER_SCENE;
	}

	if (m_pDataManager->GetStageClear())
	{
		nextScene = GAME_CLEAR_SCENE;
	}

	if (m_pInputKey->m_key[Q] == ON)
	{
		nextScene = TITLE_SCENE;
	}

	return nextScene;
}

void GameScene::Draw()
{
	if (!m_pauses)
	{
		m_pObjectManager->Draw();
	}
	else
	{
		DrawPause();
	}
}

void GameScene::ControlPause()
{

}

void GameScene::DrawPause()
{

}