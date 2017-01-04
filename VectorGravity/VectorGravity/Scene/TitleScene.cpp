/**
 * @file	TitleScene.cpp
 * @breif	タイトルシーンのクラス実装
 * @author	shibata
 */

#include "TitleScene.h"
#include "SceneFactory.h"
#include "TitleBackground.h"
#include <InputKey.h>
#include <SoundManager.h>

TitleScene::TitleScene() : 
m_pTitleBackground(new TitleBackground),
m_pInputKey(&InputKey::Instance()),
m_pSoundManager(new SoundManager)
{
	m_pSoundManager->LoadSoundFile(TITLE_SOUND, "Resource/Sound/BG_Titlescene.wav");
	m_pSoundManager->SoundState(TITLE_SOUND, Sound::LOOP);
}

TitleScene::~TitleScene()
{
	m_pSoundManager->SoundState(TITLE_SOUND, Sound::STOP);
	delete m_pTitleBackground;
	delete m_pSoundManager;

}

SceneID TitleScene::Control()
{
	m_pInputKey->CheckKey(DIK_RETURN, ENTER);

	SceneID nextScene = SceneID::TITLE_SCENE;

	if (m_pInputKey->m_key[ENTER] == ON)
	{
		nextScene = SceneID::GAME_SCENE;
	}

	return nextScene;

}

void TitleScene::Draw()
{
	m_pTitleBackground->Draw();
}