/**
 * @file	TitleScene.cpp
 * @breif	タイトルシーンのクラス実装
 * @author	shibata
 */

#include "TitleScene.h"
#include "SceneFactory.h"
#include "TitleBackground.h"
#include "TitleLogo.h"
#include "MenuButton.h"
#include <SoundManager.h>

TitleScene::TitleScene() : 
m_pTitleBackground(new TitleBackground),
m_pSoundManager(new SoundManager),
m_pTitleLogo(new TitleLogo),
m_pMenuButton(new MenuButton)
{
	m_pSoundManager->LoadSoundFile(TITLE_SOUND, "Resource/Sound/BG_Titlescene.wav");
	m_pSoundManager->SoundState(TITLE_SOUND, Sound::LOOP);
}

TitleScene::~TitleScene()
{
	m_pSoundManager->SoundState(TITLE_SOUND, Sound::STOP);
	delete m_pTitleBackground;
	delete m_pTitleLogo;
	delete m_pMenuButton;
	delete m_pSoundManager;

}

SceneID TitleScene::Control()
{

	SceneID nextScene = SceneID::TITLE_SCENE;

	if (m_pMenuButton->Control())
	{
		nextScene = SceneID::GAME_SCENE;
	}

	return nextScene;

}

void TitleScene::Draw()
{
	m_pTitleBackground->Draw();
	m_pTitleLogo->Draw();
	m_pMenuButton->Draw();
}