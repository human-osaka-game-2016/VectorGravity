/**
 * @file	GameScene.cpp
 * @breif	ゲームシーンのクラス実装
 * @author	shibata
 */

#include "GameScene.h"
#include "SceneFactory.h"
#include "../ObjectManager/ObjectManager.h"

GameScene::GameScene() :
m_pObjectManager(new ObjectManager),
m_pauses(false)
{

}

GameScene::~GameScene()
{
	delete m_pObjectManager;
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