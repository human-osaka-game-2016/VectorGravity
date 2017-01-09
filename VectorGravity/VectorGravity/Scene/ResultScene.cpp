/**
* @file	GameClear.cpp
* @breif	ゲームクリアシーンのクラス実装
* @author	shibata
*/

#include "ResultScene.h"
#include "ClearLogo.h"
#include "GameOverLogo.h"
#include "SelectButton.h"
#include "TitleMenuButton.h"
#include "CreditMenuButton.h"
#include "SceneFactory.h"
#include "../DataManager/DataManager.h"
#include <InputContlloer.h>
#include <InputKey.h>
#include <SoundManager.h>

ResultScene::ResultScene() :
m_pInputKey(&InputKey::Instance()),
m_pInputContlloer(&InputContlloer::Instance()),
m_startControlTime(NULL)
{
	m_pDataManager = DataManager::GetInstance();

	m_pSoundManager = new SoundManager;
	m_pClearLogo = new ClearLogo;
	m_pGameOverLogo = new GameOverLogo;
	m_pSelectButton = new SelectButton;
	m_pTitleMenuButton = new TitleMenuButton;
	m_pCreditMenuButton = new CreditMenuButton;

	m_pSoundManager->LoadSoundFile(CLEAR_SOUND, "Resource/Sound/BG_Sceneclear01.wav");
	m_pSoundManager->LoadSoundFile(GAMEOVER_SOUND, "Resource/Sound/BG_Sceneover01.wav");
}

ResultScene::~ResultScene()
{
	delete m_pSoundManager;
	delete m_pClearLogo;
	delete m_pGameOverLogo;
	delete m_pSelectButton;
	delete m_pTitleMenuButton;
	delete m_pCreditMenuButton;
	DataManager::Delete();
}

SceneID ResultScene::Control()
{
	SceneID nextScene = SceneID::RESULT_SCENE;

	m_pInputKey->CheckKey(DIK_RETURN, ENTER);
	m_pInputContlloer->CheckButton(XINPUT_GAMEPAD_A, A_BUTTON);

	if (m_pDataManager->GetStageClear())
	{
		m_pClearLogo->Control();
		m_pSoundManager->SoundState(CLEAR_SOUND, Sound::PLAY);
	}
	if (m_pDataManager->GetPlayerDead())
	{
		m_pGameOverLogo->Control();
		m_pSoundManager->SoundState(GAMEOVER_SOUND, Sound::PLAY);
	}
	m_pSelectButton->Control();
	m_pTitleMenuButton->Control();
	m_pCreditMenuButton->Control();

	m_startControlTime++;

	if (m_startControlTime > 180)
	{
		if (m_pInputKey->m_key[ENTER] == PUSH || m_pInputContlloer->m_padButton[CONTLLOER_1][A_BUTTON] == PUSH)
		{
			if (m_pSelectButton->GetUpOrDown())
			{
				nextScene = LOGO_SCENE;
			}
			else
			{
				nextScene = CREDIT_ROLL_SCENE;
			}
		}
	}

	if (m_startControlTime > 600)
	{
		nextScene = LOGO_SCENE;
	}

	return nextScene;
}

void ResultScene::Draw()
{
	if (m_pDataManager->GetStageClear())
	{
		m_pClearLogo->Draw();
	}
	if (m_pDataManager->GetPlayerDead())
	{
		m_pGameOverLogo->Draw();
	}
	m_pSelectButton->Draw();
	m_pTitleMenuButton->Draw();
	m_pCreditMenuButton->Draw();
}