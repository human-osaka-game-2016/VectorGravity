/**
 * @file	GameScene.cpp
 * @breif	ゲームシーンのクラス実装
 * @author	shibata
 */

#include "GameScene.h"
#include "SceneFactory.h"
#include "../ObjectManager/ObjectManager.h"
#include <SoundManager.h>

GameScene::GameScene() :
m_pObjectManager(new ObjectManager),
m_pauses(false),
m_pSoundManager(new SoundManager)
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

	if (!m_pauses)
	{
		m_pObjectManager->Control();
	}
	else
	{
		ControlPause();
	}

	return nextScene;
}

void GameScene::ControlPause()
{

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

void GameScene::DrawPause()
{

}