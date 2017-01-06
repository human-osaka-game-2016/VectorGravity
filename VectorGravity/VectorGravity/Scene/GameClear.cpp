/**
 * @file	GameClear.cpp
 * @breif	ゲームクリアシーンのクラス実装
 * @author	shibata
 */

#include "GameClear.h"
#include "SceneFactory.h"

GameClear::GameClear()
{

}

GameClear::~GameClear()
{

}

SceneID GameClear::Control()
{
	SceneID nextScene = SceneID::GAME_CLEAR_SCENE;
	
	while (m_returnLogoCount <= 60)
	{
		m_returnLogoCount++;
	}

	if (m_returnLogoCount >= 60)
	{
		nextScene = LOGO_SCENE;
	}
	m_returnLogoCount = 0;

	return nextScene;
}

void GameClear::Draw()
{

}