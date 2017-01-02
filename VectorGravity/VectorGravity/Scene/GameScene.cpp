/**
 * @file	GameScene.cpp
 * @breif	ゲームシーンのクラス実装
 * @author	shibata
 */

#include "GameScene.h"
#include "SceneFactory.h"
#include "../ObjectManager/ObjectManager.h"
#include <Sound.h>

GameScene::GameScene() :
m_pObjectManager(new ObjectManager),
m_pauses(false),
m_pSound(new Sound)
{
	m_pSound->LoadSoundFile("Resource/Sound/BG_Gamescene.wav");
	m_pSound->SoundState(Sound::LOOP);
}

GameScene::~GameScene()
{
	m_pSound->SoundState(Sound::STOP);
	delete m_pObjectManager;
	delete m_pSound;

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