/**
 * @file	TitleScene.cpp
 * @breif	タイトルシーンのクラス実装
 * @author	shibata
 */

#include "TitleScene.h"
#include "SceneFactory.h"
#include "TitleBackground.h"
#include <InputKey.h>
#include <Sound.h>

TitleScene::TitleScene() : 
m_pTitleBackground(new TitleBackground),
m_pInputKey(&InputKey::Instance()),
m_pSound(&Sound::Instance())
{
	m_pSound->LoadSoundFile("Resource/Sound/musicbox.wav");
	m_pSound->SoundState(PLAY);
}

TitleScene::~TitleScene()
{
	m_pSound->SoundState(STOP);
	delete m_pTitleBackground;
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