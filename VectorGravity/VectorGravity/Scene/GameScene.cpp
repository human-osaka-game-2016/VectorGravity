/**
* @file	GameScene.cpp
* @breif	ゲームシーンのクラス実装
* @author	shibata
*/

#include "GameScene.h"
#include "SceneFactory.h"
#include "../ObjectManager/ObjectManager.h"
#include "../DataManager/DataManager.h"
#include "../StateManager/StateManager.h"
#include "Pause.h"
#include <SoundManager.h>
#include <InputKey.h>
#include <InputContlloer.h>

GameScene::GameScene() :
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_pauses(false),
m_pPause(new Pause),
m_pStateManager(&StateManager::Instance())
{
	DataManager::Create();
	m_pDataManager = DataManager::GetInstance();

	m_pObjectManager = new ObjectManager;
	m_pSoundManager = new SoundManager;

	m_pSoundManager->LoadSoundFile(GAME_BGM, "Resource/Sound/BG_Gamescene.wav");
	m_pSoundManager->SoundState(GAME_BGM, Sound::LOOP);
}

GameScene::~GameScene()
{
	m_pSoundManager->SoundState(GAME_BGM, Sound::STOP);
	delete m_pObjectManager;
	delete m_pSoundManager;
	delete m_pPause;
	DataManager::Delete();
}

SceneID GameScene::Control()
{
	SceneID nextScene = SceneID::GAME_SCENE;

	m_pInputKey->CheckKey(DIK_Q, Q);

	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_START, START_BUTTON);

	if (!m_pStateManager->GetPauses())
	{
		if (m_pInputKey->m_key[Q] == PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][START_BUTTON] == PAD_PUSH)
		{
			m_pauses = true;
			m_pStateManager->SetPauses(m_pauses);
		}
		m_pObjectManager->Control();
	}
	else
	{
		nextScene = m_pPause->Control();
	}

	if (DataManager::GetInstance()->GetPlayerDead() || DataManager::GetInstance()->GetStageClear())
	{
		nextScene = RESULT_SCENE;
	}

	return nextScene;
}

void GameScene::Draw()
{
	m_pObjectManager->Draw();

	if (m_pStateManager->GetPauses())
	{
		m_pPause->Draw();
	}
}